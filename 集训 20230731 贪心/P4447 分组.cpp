#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int A[N], B[N];

priority_queue<int, vector<int>, greater<int>> q[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		B[i] = A[i];
	}

	sort(A + 1, A + 1 + n);
	sort(B + 1, B + 1 + n);
	m = unique(B + 1, B + 1 + n) - B - 1;

	for (int i = 1; i <= n; i++)
	{
		int cur = lower_bound(B + 1, B + 1 + m, A[i]) - B;

		if (cur == 1)
			q[cur].push(1);
		else if (A[i] != B[cur - 1] + 1)
			q[cur].push(1);
		else
		{
			if (q[cur - 1].empty())
				q[cur].push(1);
			else
			{
				int now = q[cur - 1].top();
				q[cur - 1].pop();
				q[cur].push(now + 1);
			}
		}
	}

	int ans = 2e9;
	for (int i = 1; i <= m; i++)
		if (!q[i].empty())
			ans = min(ans, q[i].top());

	printf("%d\n", ans);
	return 0;
}
