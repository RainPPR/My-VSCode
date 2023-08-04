#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int h[N], e[N], ne[N], idx;
int f[N][25], depth[N];

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

void init(int u, int fa)
{
    depth[u] = depth[fa] + 1;
    for (int i = 0; i < 20; ++i)
        f[u][i + 1] = f[f[u][i]][i];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        f[v][0] = u;
        init(v, u);
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);

    for (int i = 20; i >= 0; --i)
    {
        if (depth[f[x][i]] >= depth[y])
            x = f[x][i];
        if (x == y)
            return x;
    }

    for (int i = 20; i >= 0; --i)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main()
{
    memset(h, -1, sizeof h);
    int n, q;

    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    init(1, 0);

    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", depth[x] + depth[y] - 2 * depth[lca(x, y)]);
    }

    return 0;
}