#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e4 + 10;
const int INF = 0x3f3f3f3f;

int m, n;
int color[N];

int h[N], e[N], ne[N], idx;

int dp[N][2];

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

void dfs(int u, int fa)
{
    if (u <= n)
        return;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][0] += min(dp[v][0] - 1, dp[v][1]);
        dp[u][1] += min(dp[v][1] - 1, dp[v][0]);
    }
}

signed main()
{
    memset(h, -1, sizeof h);

    scanf("%lld %lld", &m, &n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", color + i);
    for (int i = 1; i < m; ++i)
    {
        int u, v;
        scanf("%lld %lld", &u, &v);
        add(u, v);
        add(v, u);
    }

    for (int i = 1; i <= m; ++i)
    {
        dp[i][0] = dp[i][1] = 1;
        if (i <= n)
            dp[i][!color[i]] = INF;
    }

    int root = n + 1;

    dfs(root, -1);
    printf("%lld", min(dp[root][0], dp[root][1]));

    return 0;
}