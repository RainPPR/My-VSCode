#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6;

const int N = 10010;
const int M = 10;
const int M3 = 1010;

int n, m, k, x;
int state[M3], cnt;
int dp[N][M3];

bool islin(int x)
{
	int a = -1, b = -2;
	for (int i = 1; i <= m; ++i)
	{
		b = a;
		a = x % 3;
		x /= 3;
		if (a == b)
			return true;
	}
	return false;
}

bool ischo(int a, int b)
{
	for (int i = 1; i <= m; ++i)
	{
		if (a % 3 == b % 3)
			return true;
		a /= 3, b /= 3;
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d", &k);

	int t, ct = 1;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &t);
		x = x * 3 + (t - 1);
		ct *= 3;
	}
	--ct;

	if (islin(x))
	{
		printf("0\n");
		return 0;
	}

	for (int i = 0; i <= ct; ++i)
	{
		if (!islin(i))
			state[++cnt] = i;
		if (i == x)
			dp[0][cnt] = 1;
	}

	int l1 = k - 1;
	int l2 = n - k;
	if (l1 > l2)
		swap(l1, l2);

	for (int i = 1; i <= l2; ++i)
		for (int j = 1; j <= cnt; ++j)
			for (int p = 1; p <= cnt; ++p)
				if (!ischo(state[j], state[p]))
					dp[i][j] = (dp[i][j] + dp[i - 1][p]) % MOD;

	long long a1 = 0, a2 = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		a1 = (a1 + dp[l1][i]) % MOD;
		a2 = (a2 + dp[l2][i]) % MOD;
	}

	long long ans = (a1 * a2) % MOD;

	printf("%lld\n", ans);
	return 0;
}
