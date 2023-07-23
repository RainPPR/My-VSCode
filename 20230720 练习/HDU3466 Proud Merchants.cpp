#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int M = 5010;

struct node
{
	int p, q, v;
} w[N];

bool cmp(node a, node b)
{
	return a.q - a.p < b.q - b.p;
}

int dp[M];

int main()
{
	int n, m;

	while (~scanf("%d %d", &n, &m))
	{
		memset(dp, 0, sizeof dp);

		for (int i = 1; i <= n ; ++i)
			scanf("%d %d %d", &w[i].p, &w[i].q, &w[i].v);

		sort(w + 1, w + 1 + n, cmp);

		for (int i = 1 ; i <= n ; ++i)
			for (int j = m ; j >= w[i].q ; --j)
				dp[j] = max(dp[j], dp[j - w[i].p] + w[i].v);
		
		printf("%d\n", dp[m]);
	}

	return 0;
}
