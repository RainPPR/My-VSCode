#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];

int dp[N];
int q[N];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", a + i);

	int st = 0, ed = 1;
	for (int i = 1 ; i <= n ; ++i)
	{
		while (st < ed && q[st] < i - m)
			++st;
		dp[i] = a[i] + dp[q[st]];
		while (st < ed && dp[i] < dp[q[ed - 1]])
			--ed;
		q[ed++] = i;
	}

	int ans = 1e9;
	for (int i = n - m + 1 ; i <= n ; ++i)
		if (dp[i] < ans)
			ans = dp[i];

	printf("%d\n", ans);
	return 0;
}
