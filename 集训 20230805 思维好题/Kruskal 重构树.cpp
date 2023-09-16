#include <bits/stdc++.h>

#define rr read()

using namespace std;

// INPUT GRAPH
const int N = 2e5 + 10;
const int M = 2e5 + 10;

// NEW GRAPH
const int NN = N + M;
const int MM = M + M;

// 4LCA
const int K = 20;

// FAST READ
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

// NODE, EDGE, QUERY
int n, m, q;

// INPUT GRAPH
struct e
{
    int u, v, w;
    bool operator<(const e &t) const { return w < t.w; }
} g[M];

// UNOIN
int f[NN];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

// NEW GRAPH
int d[NN], cnt;
int h[NN], e[MM], ne[MM], idx;

// 4LCA
int depth[NN];
int up[NN][K];

// ADD TO NEW GRAPH
inline void _add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

void add(int a, int b, int w)
{
    d[++cnt] = w;
    f[a] = f[b] = cnt;
    _add(a, cnt), _add(cnt, a);
    _add(b, cnt), _add(cnt, b);
}

// LCA INIT
void init(int u, int fa)
{
    depth[u] = depth[fa] + 1;
    for (int i = 1; i < K; ++i)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        up[v][0] = u, init(v, u);
    }
}

// KRUSKAL
int kruskal()
{
    sort(g + 1, g + 1 + m);

    for (int i = 1; i <= n * 2; ++i)
        f[i] = i;

    cnt = n;
    memset(h, -1, sizeof h);

    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        int u = find(g[i].u), v = find(g[i].v), &w = g[i].w;
        if (u == v)
            continue;
        res += w, add(u, v, w);
    }

    init(cnt, 0);
    return res;
}

// LCA
int lca(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);

    for (int i = K - 1; i >= 0; --i)
    {
        if (depth[up[x][i]] >= depth[y])
            x = up[x][i];
        if (x == y)
            return x;
    }

    for (int i = K - 1; i >= 0; --i)
        if (up[x][i] != up[y][i])
            x = up[x][i], y = up[y][i];
    return up[x][0];
}

int main()
{
    n = rr, m = rr;

    int a, b, w;
    for (int i = 1; i <= m; ++i)
        a = rr, b = rr, w = rr, g[i] = {a, b, w};

    q = rr;

    int res = kruskal();
    while (q--)
        printf("%d\n", d[lca(rr, rr)]);
    return 0;
}
