#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 110;

int dp[N][N];

int MAX(const int &A, const int &B)
{
	return (A > B) ? A : B;
}

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	int cmax = -1;

	for (int i = 1 ; i <= r ; ++i)
	{
		for (int j = 1 ; j <= c ; ++j)
		{
			scanf("%d", dp[i] + j);
			if (dp[i][j])
				cmax = MAX(cmax, dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1);
		}
	}

	printf("%d\n", cmax);
	return 0;
}
