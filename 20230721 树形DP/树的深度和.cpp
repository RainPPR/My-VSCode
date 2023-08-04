#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

int h[N], e[N], ne[N], idx;

int n;
int s[N], ra;

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

int dfs_f(int u, int fa, int deep)
{
    ra += deep;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        s[u] += dfs_f(v, u, deep + 1);
    }
    return s[u] + 1;
}

int res, ans;

void dfs_s(int u, int fa, int rt)
{
    int now = rt - s[u] + (n - s[u] - 1);
    if (now > res)
        res = now, ans = u;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        dfs_s(v, u, now);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    dfs_f(1, -1, 0);
    dfs_s(1, -1, ra);

    printf("%d\n", ans);
    return 0;
}