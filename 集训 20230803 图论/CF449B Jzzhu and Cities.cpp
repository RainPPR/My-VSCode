#include <bits/stdc++.h>

#define rr read()

using namespace std;

typedef pair<long long, int> PII;

const int N = 1e5 + 10;
const int M = 8e5 + 10;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

int n, m, k;

int h[N * 2], e[M], ne[M], w[M], idx;

struct _s
{
    int v, x;
} spe[N];

void add(int u, int v, int x)
{
    e[idx] = v;
    w[idx] = x;
    ne[idx] = h[u];
    h[u] = idx++;
}

void add2(int u, int v, int x)
{
    add(u, v, x);
    add(v, u, x);
}

void add2(_s t)
{
    add2(1, t.v, t.x);
}

long long dis[N * 2];
int st[N * 2], cnt[N * 2];

void dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    cnt[1] = 1;

    while (heap.size())
    {
        long long d = heap.top().first;
        int u = heap.top().second;

        heap.pop();

        if (st[u])
            continue;
        st[u] = true;

        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (dis[v] == d + w[i])
                ++cnt[v];
            else if (dis[v] > d + w[i])
            {
                dis[v] = d + w[i], cnt[v] = 1;
                heap.push({dis[v], v});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    n = rr, m = rr, k = rr;

    int a, b, c;
    for (int i = 0; i < m; ++i)
        a = rr, b = rr, c = rr, add2(a, b, c);

    for (int i = 0; i < k; ++i)
        spe[i] = {rr, rr}, add2(spe[i]);

    dijkstra();

    int res = 0;
    for (int i = 0; i < k; ++i)
    {
        const int &v = spe[i].v, &w = spe[i].x;
        if (dis[v] < w)
            ++res;
        else if (dis[v] == w && cnt[v] > 1)
            ++res, --cnt[v];
    }

    printf("%d\n", res);
    return 0;
}