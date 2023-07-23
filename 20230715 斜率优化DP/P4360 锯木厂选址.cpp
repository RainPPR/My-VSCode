#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10;

int n;
int sum[N];
int dis[N];

int dp[N];
int q[N];

signed main()
{
    scanf("%lld", &n);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld %lld", sum + i, dis + i);
        sum[i] += sum[i - 1];
    }

    for (int i = n; i >= 1; --i)
    {
        dis[i] += dis[i + 1];
        dp[0] += dis[i] * (sum[i] - sum[i - 1]);
    }

    int ans = LONG_LONG_MAX;

    int st = 1, ed = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[0] - sum[i] * dis[i];
        while (st < ed && dp[q[st + 1]] - dp[q[st]] <= -dis[i] * (sum[q[st + 1]] - sum[q[st]]))
            ++st;
        if (i > 1)
            ans = min(ans, dp[q[st]] - dis[i] * (sum[i] - sum[q[st]]));
        while (st < ed && (dp[q[ed]] - dp[q[ed - 1]]) * (sum[i] - sum[q[ed]]) >= (dp[i] - dp[q[ed]]) * (sum[q[ed]] - sum[q[ed - 1]]))
            --ed;
        q[++ed] = i;
    }

    printf("%lld\n", ans);
}