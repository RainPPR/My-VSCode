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

int f[N][N][N][N];

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

	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= n ; ++j)
		{
			for (int x = 1 ; x <= n ; ++x)
			{
				for (int y = 1 ; y <= n ; ++y)
				{
					f[i][j][x][y] = MAX(f[i - 1][j][x - 1][y], f[i - 1][j][x][y - 1], f[i][j - 1][x - 1][y], f[i][j - 1][x][y - 1]) + a[i][j];

					if (i != x && j != y)
						f[i][j][x][y] += a[x][y];
				}
			}
		}
	}

	printf("%d", f[n][n][n][n]);
	return 0;
}
