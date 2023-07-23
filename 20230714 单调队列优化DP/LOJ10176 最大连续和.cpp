#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];
int q[N];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}

	int ans = -2e9;

	int st = 0, ed = 1;
	for (int i = 1 ; i <= n ; ++i)
	{
		while (st < ed && q[st] < i - m)
			++st;

		int t = a[i] - a[q[st]];
		if (t > ans)
			ans = t;

		while (st < ed && a[i] < a[q[ed - 1]])
			--ed;
		q[ed++] = i;
	}

	printf("%d\n", ans);
	return 0;
}

