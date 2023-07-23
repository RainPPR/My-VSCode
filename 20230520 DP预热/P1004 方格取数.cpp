#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 11;

int n;
int a[N][N];

int dp[N][N][N][N];

int main()
{
	int n;
	scanf("%d", &n);

	int x, y, p;
	while (1)
	{
		scanf("%d %d %d", &x, &y, &p);
		if (x && y && p)
			a[x][y] = p;
		else
			break;
	}

	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= n ; ++j)
		{
			for (int h = 1 ; h <= n ; ++h)
			{
				for (int k = 1 ; k <= n ; ++k)
				{
					dp[i][j][h][k] = max({dp[i - 1][j][h - 1][k], dp[i][j - 1][h][k - 1], dp[i - 1][j][h][k - 1], dp[i][j - 1][h - 1][k]}) + a[i][j];
					if (i != h && j != k)
						dp[i][j][h][k] += a[h][k];
				}
			}
		}
	}

	printf("%d\n", dp[n][n][n][n]);
	return 0;
}
