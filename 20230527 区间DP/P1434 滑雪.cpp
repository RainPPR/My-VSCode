#include <bits/stdc++.h>

using namespace std;

const int N = 110;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m;
int a[N][N];

int f[N][N];

int dfs(int i, int j)
{
	if (f[i][j])
		return f[i][j];

	f[i][j] = 1;

	for (int t = 0 ; t < 4 ; ++t)
	{
		int x = i + dx[t], y = j + dy[t];
		if (x < 1 || y < 1 || x > n || y > m)
			continue;

		if (a[x][y] < a[i][j])
			f[i][j] = max(f[i][j], dfs(x, y) + 1);
	}

	return f[i][j];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			scanf("%d", a[i] + j);

	int ans = 0;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			ans = max(ans, dfs(i, j));

	printf("%d\n", ans);
	return 0;
}
