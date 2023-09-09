#include <bits/stdc++.h>

#define int long long
#define rr read()

using namespace std;

const int N = 1e5 + 10;
const int K = 3e5 + 10;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

inline int MIN(const int &a, const int &b)
{
    return a < b ? a : b;
}

int n, m, q, idx;
unordered_map<int, int> pointno[N];
vector<int> station_point[N];

struct edge
{
    int v;
    int d, hc;
};

vector<edge> g[K];
void add(int u, int v, int go, int hc) { g[u].push_back({v, go, hc}); }

struct node
{
    int d, u;
    int gs, hc;

    bool operator<(const node &t) const { return d == t.d ? gs < t.gs : d < t.d; }
    bool operator>(const node &t) const { return d == t.d ? gs > t.gs : d > t.d; }
};

int dis[K];
bool st[K];

int solve(const int &a, const int &b, const int &limit)
{
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);

    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i : station_point[1])
        dis[pointno[1][i]] = 0, heap.push({0, pointno[1][i], 0, 0});

    while (heap.size())
    {
        node t = heap.top();
        heap.pop();

        if (st[t.u])
            continue;
        st[t.u] = true;

        for (edge i : g[t.u])
        {
            if (dis[i.v] > dis[t.u] + i.d * a + i.hc * b && t.hc + i.hc <= limit)
            {
                dis[i.v] = dis[t.u] + i.d * a + i.hc * b;
                heap.push({dis[i.v], i.v, i.d * a + i.hc * b, t.hc + i.hc});
            }
        }
    }

    int res = 4e18;
    for (int i : station_point[n])
        res = MIN(res, dis[pointno[n][i]]);
    return res;
}

signed main()
{
    n = rr, m = rr, q = rr;

    for (int i = 1; i <= m; ++i)
    {
        int k = rr, lt = rr;

        pointno[lt][i] = ++idx;
        for (int j : station_point[lt])
            add(idx, pointno[lt][j], 0, 1), add(pointno[lt][j], idx, 0, 1);

        station_point[lt].push_back(i);
        lt = idx;

        for (int j = 2; j <= k; ++j)
        {
            int u = rr;

            pointno[u][i] = ++idx;
            for (int j : station_point[u])
                add(idx, pointno[u][j], 0, 1), add(pointno[u][j], idx, 0, 1);

            station_point[u].push_back(i);

            add(lt, idx, 1, 0);
            lt = idx;
        }
    }

    while (q--)
    {
        int a = rr, b = rr, c = rr;
        printf("%lld\n", solve(a, b, c));
    }

    return 0;
}
