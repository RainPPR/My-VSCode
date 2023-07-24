#include <bits/stdc++.h>

using namespace std;

const int N = 300;
const int INF = 0x3f3f3f3f;

int n, q;

int child[N];
int edge[N][2];
int apple[N][2];

int dp[N][N];

int getdp(int, int);

void dfs(int u, int keep)
{
    if (!child[u] || !keep)
        return;
    if (dp[u][keep])
        return;
    dp[u][keep] = max(getdp(edge[u][0], keep - 1) + apple[u][0], getdp(edge[u][1], keep - 1) + apple[u][1]);
    for (int k = 1; k < keep; ++k)
        dp[u][keep] = max(dp[u][keep], getdp(edge[u][0], k - 1) + getdp(edge[u][1], keep - k - 1) + apple[u][0] + apple[u][1]);
}

int getdp(int u, int keep)
{
    if (!dp[u][keep])
        dfs(u, keep);
    return dp[u][keep];
}

int main()
{
    scanf("%d %d", &n, &q);

    for (int i = 1; i < n; ++i)
    {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        edge[u][child[u]] = v;
        apple[u][child[u]] = x;
        ++child[u];
    }

    dfs(1, q);
    printf("%d\n", dp[1][q]);

    return 0;
}