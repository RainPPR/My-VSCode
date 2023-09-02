#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int K = 11;
const int NN = 1e4;
const int MM = 5e4;

const int N = 4e5 + 10;
const int M = 4e6 + 10;

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
int s, t;

int h[N], e[M], w[M], ne[M], idx;

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

int dis[N];
bool st[N];

void dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, s});

    while (heap.size())
    {
        int d = heap.top().first, u = heap.top().second;
        heap.pop();

        if (st[u])
            continue;
        st[u] = true;

        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (dis[v] > d + w[i])
                dis[v] = d + w[i], heap.push({dis[v], v});
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);

    n = rr, m = rr, k = rr;
    s = rr, t = rr;

    for (int i = 0; i < m; ++i)
    {
        int u = rr, v = rr, x = rr;
        for (int j = 0; j <= k; ++j)
            add2(u + j * NN, v + j * NN, x);
        for (int j = 1; j <= k; ++j)
            add(u + j * NN - NN, v + j * NN, 0), add(v + j * NN - NN, u + j * NN, 0);
    }

    dijkstra();

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i)
        ans = min(ans, dis[t + i * NN]);

    printf("%d\n", ans);
    return 0;
}