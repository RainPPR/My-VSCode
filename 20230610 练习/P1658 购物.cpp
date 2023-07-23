#include <bits/stdc++.h>

using namespace std;

int x, n;
int a[20];

int main()
{
	scanf("%d %d", &x, &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", a + i);

	sort(a + 1, a + n + 1);

	if (a[1] != 1)
	{
		printf("-1\n");
		return 0;
	}

	int sum = 0, ans = 0;
	while (sum < x)
	{
		for (int i = n ; i >= 1 ; i--)
		{
			if (a[i] <= sum + 1)
			{
				ans++;
				sum += a[i];
				break;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
