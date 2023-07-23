#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
vector<int> G[N];

int cnt[N], dp[N];

void dfs(int u, int f)
{
	cnt[u] = 1;
	for (int v : G[u])
	{
		if (v == f)
			continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		dp[u] = max(dp[u], cnt[v]);
	}
	dp[u] = max(dp[u], n - cnt[u]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i < n ; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1, -1);

	int cm = 2e9;
	for (int i = 1 ; i <= n ; ++i)
		if (dp[i] < cm)
			cm = dp[i];

	printf("%d\n", cm);
	return 0;
}
