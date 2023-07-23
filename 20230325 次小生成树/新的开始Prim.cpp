#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 310;
const int INF = 0x3f3f3f3f;

int n;
int e[N][N];

int dis[N];
bool vis[N];

int Prim()
{
	dis[1] = 0;
	vis[1] = 1;
	for (int i = 1 ; i <= n ; ++i)
		dis[i] = e[1][i];

	int ans = 0;
	for (int i = 2 ; i <= n ; ++i)
	{
		int p = -1, cmin = INF;
		for (int j = 1 ; j <= n ; ++j)
			if (!vis[j] && dis[j] < cmin)
				cmin = dis[j], p = j;

		if (cmin == INF)
			continue;
		vis[p] = true;
		ans += cmin;

		for (int j = 1 ; j <= n ; ++j)
			if (!vis[j] && e[p][j] < dis[j])
				dis[j] = e[p][j];
	}

	return ans;
}

int main()
{
	memset(e, 0x3f, sizeof e);

	int k;
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &k);
		e[i][n + 1] = e[n + 1][i] = k;
	}
	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= n ; ++j)
		{
			scanf("%d", &k);
			e[i][j] = e[j][i] = k;
		}
	}
	++n;

	const int ans = Prim();
	printf("%d\n", ans);

	return 0;
}
