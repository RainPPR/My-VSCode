#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int h[N], e[N], ne[N], idx;

int r[N];
int dp[N][2];

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

void dfs(int u, int fa)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    dp[u][1] += r[u];
}

int main()
{
    memset(h, -1, sizeof h);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", r + i);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    dfs(1, -1);

    printf("%d\n", max(dp[1][0], dp[1][1]));
    return 0;
}