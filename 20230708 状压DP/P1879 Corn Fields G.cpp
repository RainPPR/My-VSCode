#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e8;

const int N = 15;
const int C = (1 << N) - 1;

int n, m;
int cnt;

int could[N];
int dp[N][C];
int state[C], st;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cnt = (1 << m) - 1;

	for (int i = 1 ; i <= n ; ++i)
	{
		int t;
		for (int j = 1 ; j <= m ; ++j)
		{
			cin >> t;
			could[i] = (could[i] << 1) | (t ^ 1);
		}
	}

	st = 0;
	for (int i = 0 ; i <= cnt ; ++i)
	{
		if (i & i << 1)
			continue;
		state[++st] = i;
	}
	cnt = st;

	dp[0][1] = 1;
	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= cnt ; ++j)
		{
			if (state[j] & could[i])
				continue;
			for (int k = 1 ; k <= cnt ; ++k)
			{
				if (state[j] & state[k])
					continue;
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}

	int ans = 0;
	for (int i = 1 ; i <= cnt ; ++i)
	{
		if (state[i] & could[n])
			continue;
		ans = (ans + dp[n][i]) % MOD;
	}

	cout << ans << endl;
	return 0;
}
