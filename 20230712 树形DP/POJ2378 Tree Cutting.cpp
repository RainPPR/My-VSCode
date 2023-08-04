#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int N = 1e4 + 10;

int n;
vector<int> G[N];

int cnt[N], dp[N];
vector<int> ans;

void dfs(int u, int f)
{
	cnt[u] = 1;
	for (int i = 0 ; i < G[u].size() ; ++i)
	{
		int v = G[u][i];
		if (v == f)
			continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		dp[u] = max(dp[u], cnt[v]);
	}
	dp[u] = max(dp[u], n - cnt[u]);
	if (dp[u] <= n / 2)
		ans.push_back(u);
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

	sort(ans.begin(), ans.end());

	if (ans.size())
		for (int i = 0 ; i < ans.size() ; ++i)
			printf("%d\n", ans[i]);
	else
		printf("NONE\n");
	return 0;
}
