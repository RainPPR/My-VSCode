#include <cstdio>

const int N = 1e6 + 10;

int le[N], rt[N];
int n;

int MAX(const int a, const int b)
{
	return (a > b) ? a : b;
}

int dfs(int x)
{
	if (x == 0)
		return 0;

	int l = dfs(le[x]);
	int r = dfs(rt[x]);

	return MAX(l, r) + 1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d %d", le + i, rt + i);

	printf("%d\n", dfs(1));

	return 0;
}
