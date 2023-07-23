/*
    dp[i] 表示考虑前 i 个任务做完的花费 + 后续将多出的费用
    j 表示 (j, i] 为一个批次
    dp[i] = min(dp[j] + t[i] * (f[i] - f[j]) + s * (f[n] - f[j]))
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e5 + 10;

int n, s;
int t[N], f[N];

int dp[N];

signed main()
{
    scanf("%lld", &n);
    scanf("%lld", &s);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld %lld", t + i, f + i);
        t[i] += t[i - 1];
        f[i] += f[i - 1];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] = min(dp[i], dp[j] + t[i] * (f[i] - f[j]) + s * (f[n] - f[j]));

    printf("%lld\n", dp[n]);
    return 0;
}
