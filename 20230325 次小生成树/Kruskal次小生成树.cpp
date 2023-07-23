#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1010;
const int M = N * (N - 1) / 2;
const int INF = 0x3f3f3f3f;

int n, m;

struct edge
{
	int u, v, w;
	bool used;
	bool operator < (const edge &a) const
	{
		return this->w < a.w;
	}
} edges[M];

int father[N];
int find(int x)
{
	if (x == father[x])
		return x;
	father[x] = find(father[x]);
	return father[x];
}

int maxd[N][N];

int Kruskal()
{
	for (int i = 1 ; i <= n ; ++i)
		father[i] = i;

	int ans = 0;
	for (int i = 1 ; i <= m ; ++i)
	{
		const int f1 = find(edges[i].u), f2 = find(edges[i].v);

		if (f1 != f2)
		{
			edges[i].used = true;
			ans += edges[i].w;

			for (int j = 1 ; j <= n ; ++j)
			{
				const int fj = find(j);
				if (fj == f1)
					maxd[j][f2] = maxd[f2][j] = edges[i].w;
				else if (fj == f2)
					maxd[j][f1] = maxd[f1][j] = edges[i].w;
			}

			father[f1] = f2;
		}
	}

	return ans;
}

int sKruskal(int res)
{
	int ans = INF;
	for (int i = 1 ; i <= m ; ++i)
		if (!edges[i].used)
			ans = min(ans, res - maxd[edges[i].u][edges[i].v] + edges[i].w);
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		edges[i].used = false;
	}

	sort(edges + 1, edges + 1 + m);

	const int ans1 = Kruskal();
	const int ans2 = sKruskal(ans1);
	printf("%d\n", ans2);

	return 0;
}
