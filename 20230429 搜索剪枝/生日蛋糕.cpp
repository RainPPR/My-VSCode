#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int M = 20;
const int INF = 0x3f3f3f3f;

int n, m;
int minv[M], mins[M];

int ans = INF;

int MIN(const int &a, const int &b)
{
	return (a < b) ? a : b;
}

void dfs(int depth, int sumv, int sums, int r, int h)
{
	if (depth == 0)
	{
		if (sumv == n && sums < ans)
			ans = sums;
		return ;
	}

	if (sumv + minv[depth - 1] > n || sums + mins[depth - 1] > ans || sums + 2 * (n - sumv) / r >= ans)
		return ;

	for (int i = r - 1 ; i >= depth ; --i)
	{
		if (depth == m)
			sums = i * i;

		int maxh = MIN((n - sumv - minv[depth - 1]) / (i * i), h - 1);
		for (int j = maxh ; j >= depth ; --j)
			dfs(depth - 1, sumv + i * i * j, sums + 2 * i * j, i, j);
	}
}

int main()
{
	scanf("%d%d", &n, &m);

	int maxr = sqrt(n);
	int maxh = n;

	minv[0] = mins[0] = 0;
	for (int i = 1 ; i <= m ; ++i)
	{
		minv[i] = minv[i - 1] + i * i * i;
		mins[i] = mins[i - 1] + 2 * i * i;
	}

	dfs(m, 0, 0, maxr, maxh);

	if (ans == INF)
		ans = 0;
	printf("%d", ans);

	return 0;
}
