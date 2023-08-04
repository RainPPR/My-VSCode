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

int dict(int x, int y)
{
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int dict(int x, int y, int z, int l)
{
    return dict(x, l) + dict(y, l) + dict(z, l);
}

void gmi(int &pos, int &mi, int now, int len)
{
    if (len < mi)
        mi = len, pos = now;
}

int main()
{
    memset(h, -1, sizeof h);
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    init(1, 0);

    for (int i = 1; i <= q; ++i)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        int pos = -1, mi = 2e9;
        gmi(pos, mi, x, dict(x, y, z, x));
        gmi(pos, mi, y, dict(x, y, z, y));
        gmi(pos, mi, z, dict(x, y, z, z));
        gmi(pos, mi, lca(x, y), dict(x, y, z, lca(x, y)));
        gmi(pos, mi, lca(x, z), dict(x, y, z, lca(x, z)));
        gmi(pos, mi, lca(y, z), dict(x, y, z, lca(y, z)));
        gmi(pos, mi, lca(lca(x, y), z), dict(x, y, z, lca(lca(x, y), z)));
        printf("%d %d\n", pos, mi);
    }

    return 0;
}