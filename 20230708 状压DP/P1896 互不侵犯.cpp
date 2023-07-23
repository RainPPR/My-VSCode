#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 12;
const int K = 110;
const int C = (1 << 12) + 10;

int n, k;
int cnt;

int dp[N][C][K];
int state[C], st;
int king[C];

int lobit(int x)
{
	return x & -x;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	cnt = (1 << n) - 1;

	st = 0;
	for (int i = 0 ; i <= cnt ; ++i)
	{
		if (i & i << 1)
			continue;
		int t = state[++st] = i;
		while (t)
			t -= lobit(t), ++king[st];
	}
	cnt = st;

	for (int i = 1 ; i <= cnt ; ++i)
		if (king[i] <= k)
			dp[1][i][king[i]] = 1;

	for (int i = 2 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= cnt ; ++j)
		{
			for (int s = 1 ; s <= cnt ; ++s)
			{
				if (state[j] & state[s])
					continue;
				if (state[j] << 1 & state[s])
					continue;
				if (state[j] >> 1 & state[s])
					continue;
				for (int t = 1 ; t <= k - king[j] ; ++t)
					dp[i][j][t + king[j]] += dp[i - 1][s][t];
			}
		}
	}

	int ans = 0;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= cnt ; ++j)
			ans += dp[i][j][k];

	cout << ans << endl;
	return 0;
}

