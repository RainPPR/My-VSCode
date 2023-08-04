#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
const int INF = 0x3f3f3f3f;

int h[N], w[N], e[N], ne[N], idx;
int down1[N], down2[N], up[N], p[N];

void add(int u, int v, int x)
{
    w[idx] = x;
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

int dfs_down(int u, int fa)
{
    down1[u] = down2[u] = -INF;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        int d = dfs_down(v, u) + w[i];
        if (d > down1[u])
            down2[u] = down1[u], down1[u] = d, p[u] = v;
        else if (d > down2[u])
            down2[u] = d;
    }

    if (down1[u] == -INF && down2[u] == -INF)
        down1[u] = down2[u] = 0;
    return down1[u];
}

void dfs_up(int u, int fa)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        if (p[u] == v)
            up[v] = max(up[u], down2[u]) + w[i];
        else
            up[v] = max(up[u], down1[u]) + w[i];

        dfs_up(v, u);
    }
}

int main()
{
    memset(h, -1, sizeof h);

    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; ++i)
    {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        add(u, v, x);
        add(v, u, x);
    }

    dfs_down(1, 0);
    dfs_up(1, 0);

    int ans = INF;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, max(down1[i], up[i]));

    printf("%d\n", ans);
    return 0;
}