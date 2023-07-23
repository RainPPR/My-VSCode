#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
const int INF = 0x3f3f3f3f;

int h[N], e[N], ne[N], idx;
int down1[N], down2[N], up[N], p[N];

void add(int u, int v)
{
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

        int d = dfs_down(v, u) + 1;
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
            up[v] = max(up[u], down2[u]) + 1;
        else
            up[v] = max(up[u], down1[u]) + 1;

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
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    dfs_down(1, 0);
    dfs_up(1, 0);

    int res = INF;
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        int t = max(down1[i], up[i]);
        if (t == res)
            ans.push_back(i);
        else if (t < res)
        {
            res = t;
            ans.clear();
            ans.push_back(i);
        }
    }

    for (int i : ans)
        printf("%d ", i);
    return 0;
}