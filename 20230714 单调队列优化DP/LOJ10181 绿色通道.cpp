// dp[i] = min(dp[j]) + a[i] (i - tmax - 1 <= j < i)

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

int n, t;
int a[N];

int q[N];
int dp[N];

int nt(int tmax)
{
	int st = 0, ed = 1;
	for (int i = 1 ; i <= n ; ++i)
	{
		while (st < ed && q[st] < i - tmax - 1)
			++st;

		dp[i] = dp[q[st]] + a[i];

		while (st < ed && dp[i] < dp[q[ed - 1]])
			--ed;
		q[ed++] = i;
	}

	int ans = 2e9;
	for (int i = n - tmax ; i <= n ; ++i)
		if (dp[i] < ans)
			ans = dp[i];
	return ans;
}

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", a + i);

	int l = 0, r = n;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (nt(mid) <= t)
			r = mid;
		else
			l = mid + 1;
	}

	printf("%d\n", l);
	return 0;
}
