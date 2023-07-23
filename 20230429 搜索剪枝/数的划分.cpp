#include <cstdio>

using namespace std;

const int K = 10;

int n, k;
int a[K];

int ans;

void dfs(int rest, int sum)
{
	if (rest == 0)
	{
		if (sum == n)
			++ans;
		return ;
	}

	for (int i = a[rest + 1] ; i * rest <= n - sum ; ++i)
	{
		a[rest] = i;
		dfs(rest - 1, sum + i);
	}
}

int main()
{
	scanf("%d %d", &n, &k);

	a[k + 1] = 1;
	dfs(k, 0);

	printf("%d", ans);
	return 0;
}
