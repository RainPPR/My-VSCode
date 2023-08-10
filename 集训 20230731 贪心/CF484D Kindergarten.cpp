#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 10;

int a[N];
int dp[N];

signed main()
{
    int n;
    scanf("%lld", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);

    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; ++i)
    {
        if ((a[i - 2] < a[i - 1] && a[i - 1] < a[i]) || (a[i - 2] > a[i - 1] && a[i - 1] > a[i]))
            dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
        else
            dp[i] = max(dp[i - 1], dp[i - 2] + abs(a[i] - a[i - 1]));
    }

    printf("%lld\n", dp[n]);
}