#include <cstdio>

const int N = 30;
const int M = 100;

int n;
int a[N][N];

int f[N][N][M];

int main()
{
	scanf("%d", &n);

	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= i ; ++j)
		{
			scanf("%d", a[i] + j);
			for (int k = 0 ; k < M ; ++k)
				f[i][j][k] = f[i][j][k] || f[i - 1][j - 1][(k - a[i][j] + M) % M] || f[i - 1][j][(k - a[i][j] + M) % M];
		}
	}

	int ans = -1;
	for (int i = 1 ; i < n ; ++i)
		for (int j = 0 ; j < M ; ++j)
			if (f[n][i][j] && j > ans)
				ans = j;

	printf("%d\n", ans);
	return 0;
}
