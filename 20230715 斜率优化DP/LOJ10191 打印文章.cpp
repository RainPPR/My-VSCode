#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m;
int s[N];

int q[N];
int dp[N];

int Gx(int k1, int k2)
{
	return s[k2] - s[k1];
}

int Gy(int k1, int k2)
{
	return (dp[k2] + s[k2] * s[k2]) - (dp[k1] + s[k1] * s[k1]);
}

int Ga(int i, int j)
{
	return dp[j] + (s[i] - s[j]) * (s[i] - s[j]) + m;
}

signed main()
{
	while (~scanf("%lld %lld", &n, &m))
	{
		for (int i = 1 ; i <= n ; ++i)
		{
			scanf("%lld", s + i);
			s[i] += s[i - 1];
		}

		int st = 0, ed = 1;
		for (int i = 1 ; i <= n ; ++i)
		{
			while (st + 1 < ed && Gy(q[st], q[st + 1]) <= 2 * s[i] * Gx(q[st], q[st + 1]))
				++st;
			dp[i] = Ga(i, q[st]);
			while (st + 1 < ed && Gy(q[ed - 1], i) * Gx(q[ed - 2], q[ed - 1]) <= Gy(q[ed - 2], q[ed - 1]) * Gx(q[ed - 1], i))
				--ed;
			q[ed++] = i;
		}

		printf("%lld\n", dp[n]);
	}

	return 0;
}
