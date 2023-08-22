#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int border[N];

int h[N], e[N], ne[N], idx;

int f[N][25], depth[N];

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

void init(string str)
{
    border[0] = -1;
    for (int j = 0, k = -1; j < str.size();)
    {
        if (k == -1 || str[j] == str[k])
            border[++j] = ++k, add(k, j);
        else
            k = border[k];
    }
}

void build(int u, int fa)
{
    depth[u] = depth[fa] + 1;
    for (int i = 0; i < 20; ++i)
        f[u][i + 1] = f[f[u][i]][i];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        f[v][0] = u;
        build(v, u);
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
            return border[x];
    }

    for (int i = 20; i >= 0; --i)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main()
{
    memset(h, -1, sizeof h);

    string str;
    cin >> str;

    init(str);
    build(0, -1);

    int m;
    scanf("%d", &m);

    while (m--)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        printf("%d\n", lca(p, q));
    }

    return 0;
}