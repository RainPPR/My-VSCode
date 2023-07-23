/*
    dp[i] 只考虑前i个奶牛
    从第i个奶牛向前要到第j个
    dp[i] = max(sum[j ... i] + dp[j - 2])
          = max(sum[i] - sum[j - 1] + dp[j - 2])
          = max(dp[j - 2] - sum[j - 1]) + sum[i]
        (i - k + 1 <= j <= i)

        ----- i
    1 2 3 4 5 6 7 8

    开 ll
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;

int s[N];
int dp[N];

int q[N];

int getx(int j)
{
	return dp[j - 2] - s[j - 1];
}

signed main()
{
	int n, k;
	scanf("%lld %lld", &n, &k);

	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%lld", s + i);
		s[i] += s[i - 1];
	}

	int ans = -2e9;

	int st = 0, ed = 1;
	for (int i = 1 ; i <= n ; ++i)
	{
		while (st < ed && q[st] < i - k + 1)
			++st;

		while (st < ed && getx(i) > getx(q[ed - 1]))
			--ed;
		q[ed++] = i;

		dp[i] = s[i] + getx(q[st]);
		if (dp[i] > ans)
			ans = dp[i];
	}

	printf("%lld\n", ans);
	return 0;
}

