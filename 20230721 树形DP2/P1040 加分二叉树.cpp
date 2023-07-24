#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 50;

int n;
int dp[N][N];
int from[N][N];

void print(int l, int r)
{
    if (l > r)
        return;
    printf("%lld ", from[l][r]);
    print(l, from[l][r] - 1);
    print(from[l][r] + 1, r);
}

signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", dp[i] + i);
        dp[i][i - 1] = 1;
        from[i][i] = i;
    }

    for (int l = 2; l <= n; ++l)
    {
        for (int i = 1; i <= n - l + 1; ++i)
        {
            int j = i + l - 1;
            dp[i][j] = dp[i][i] + dp[i + 1][j], from[i][j] = i;
            for (int k = i + 1; k < j; ++k)
                if (dp[i][k - 1] * dp[k + 1][j] + dp[k][k] > dp[i][j])
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k], from[i][j] = k;
        }
    }

    printf("%lld\n", dp[1][n]);
    print(1, n);
    return 0;
}