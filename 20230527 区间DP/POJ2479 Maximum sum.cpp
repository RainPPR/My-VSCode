// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;

int a[N];
int dp[2][N];

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);

        for (int i = 1; i <= n; ++i)
            dp[0][i] = max(dp[0][i - 1] + a[i], a[i]);
        for (int i = n; i >= 1; --i)
            dp[1][i] = max(dp[1][i + 1] + a[i], a[i]);

        int mk = -2e9, ans = -2e9;
        for (int i = 2; i <= n; ++i)
        {
            mk = max(mk, dp[0][i - 1]);
            ans = max(ans, mk + dp[1][i]);
        }

        printf("%d\n", ans);
    }

    return 0;
}