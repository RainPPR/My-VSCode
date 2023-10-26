#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10;

int read()
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

int a[N], b[N];

int h[N], e[2 * N], ne[2 * N], idx;

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

int f[N], sz[N], ce[N], dth[N];

int find(int x)
{
    return x == f[x] ? x : find(f[x]);
}

int ans[N];

void dfs(int u, int fa)
{
    int x = find(a[u]), y = find(b[u]);
    if (dth[x] < dth[y])
        swap(x, y);

    int tmp = dth[x];
    ans[u] = ans[fa] - min(sz[x], ce[x]);

    ++ce[x];
    if (x != y)
    {
        ans[u] -= min(sz[y], ce[y]);
        f[y] = x;
        sz[x] += sz[y], ce[x] += ce[y];
        dth[x] += (dth[x] == dth[y]);
    }

    ans[u] += min(sz[x], ce[x]);

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        dfs(v, u);
    }

    --ce[x];
    if (x != y)
    {
        f[y] = y;
        sz[x] -= sz[y], ce[x] -= ce[y];
        dth[x] = tmp;
    }
}

signed main()
{
    memset(h, -1, sizeof h);

    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read(), b[i] = read();
    for (int i = 1; i < n; ++i)
    {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }

    for (int i = 1; i <= n; ++i)
        f[i] = i, sz[i] = 1, ce[i] = 0, dth[i] = 1;

    dfs(1, 0);

    for (int i = 2; i <= n; ++i)
        printf("%lld ", ans[i]);
    return 0;
}