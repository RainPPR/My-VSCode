#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;

int n, m;
int e[N][N];

int dis[N], pre[N], maxd[N][N];
bool vis[N], used[N][N];

int Prim()
{
	memset(vis, 0, sizeof vis);
	memset(used, 0, sizeof used);
	memset(maxd, 0, sizeof maxd);

	vis[1] = true;
	pre[1] = -1;
	dis[1] = 0;

	for (int i = 2 ; i <= n ; ++i)
		pre[i] = 1, dis[i] = e[1][i];

	int ans = 0;
	for (int i = 2 ; i <= n ; ++i)
	{
		int cmin = INF, p = -1;
		for (int j = 1 ; j <= n ; ++j)
			if (!vis[j] && dis[j] < cmin)
				cmin = dis[j], p = j;

		if (cmin == INF)
			return -1;

		vis[p] = true;
		ans += cmin;
		used[p][pre[p]] = used[pre[p]][p] = true;

		for (int j = 1 ; j <= n ; ++j)
		{
			if (vis[j] && j != p)
				maxd[j][p] = maxd[p][j] = max(maxd[j][pre[p]], dis[p]);
			if (!vis[j] && e[p][j] < dis[j])
				dis[j] = e[p][j], pre[j] = p;
		}
	}

	return ans;
}

int sPrim(const int res)
{
	int ans = INF;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = i + 1 ; j <= n ; ++j)
			if (!used[i][j] && e[i][j] != INF)
				ans = min(ans, res - maxd[i][j] + e[i][j]);
	return ans;
}

int main()
{
	memset(e, 0x3f, sizeof e);

	scanf("%d %d", &n, &m);
	int u, v, w;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		e[u][v] = e[v][u] = w;
	}

	const int ans1 = Prim();
	const int ans2 = sPrim(ans1);
	printf("%d\n", ans2);

	return 0;
}
