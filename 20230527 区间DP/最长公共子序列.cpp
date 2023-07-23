// Future never has to do with past time, but present does.

#include <cstdio>

const int N = 1e3 + 10;

int MAX(const int &a, const int &b)
{
	return (a > b) ? a : b;
}

int n;
int a[N], b[N];

int f[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", a + i);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", b + i);

	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= n ; ++j)
		{
			f[i][j] = MAX(f[i - 1][j], f[i][j - 1]);
			if (a[i] == a[j])
				f[i][j] = MAX(f[i][j], f[i - 1][j - 1] + 1);
		}
	}

	printf("%d", f[n][n]);
	return 0;
}
