#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 11;

int MAX(const int &a, const int &b, const int &c, const int &d)
{
	if (a < b)
	{
		if (b < c)
		{
			if (c < d)
				return d;
			else
				return c;
		}
		else
		{
			if (b < d)
				return d;
			else
				return b;
		}
	}
	else
	{
		if (a < c)
		{
			if (c < d)
				return d;
			else
				return c;
		}
		else
		{
			if (a < d)
				return d;
			else
				return a;
		}
	}
}

int n;
int a[N][N];

int f[N * 2][N][N];

int main()
{
	scanf("%d", &n);

	int p1, p2, c;
	while (1)
	{
		scanf("%d %d %d", &p1, &p2, &c);

		if (p1 && p2 && c)
			a[p1][p2] = c;
		else
			break;
	}

	for (int k = 1 ; k <= 2 * n ; ++k)
	{
		for (int i = 1 ; i <= k ; ++i)
		{
			for (int j = 1 ; j <= k ; ++j)
			{
				f[k][i][j] = MAX(f[k - 1][i][j], f[k - 1][i - 1][j], f[k - 1][i][j - 1], f[k - 1][i - 1][j - 1]);
				if (i == j)
					f[k][i][j] += a[k - i][i];
				else
					f[k][i][j] += a[k - i][i] + a[k - j][j];
			}
		}
	}

	printf("%d", f[n * 2][n][n]);
	return 0;
}
