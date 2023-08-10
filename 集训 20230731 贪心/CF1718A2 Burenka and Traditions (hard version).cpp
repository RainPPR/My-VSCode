#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;

int dp[N];

signed main()
{
    int T;
    scanf("%lld", &T);

    while (T--)
    {
        int n;
        scanf("%lld", &n);

        map<int, int> pos;
        pos[0] = 0;

        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            int a;
            scanf("%lld", &a);

            res ^= a;
            dp[i] = dp[i - 1] + 1;
            if (pos.count(res))
                dp[i] = min(dp[i], dp[pos[res]] + i - pos[res] - 1);

            pos[res] = i;
        }

        printf("%lld\n", dp[n]);
    }

    return 0;
}