#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 510;
const int M = N * (N - 1) / 2;
const int INF = 0x3f3f3f3f;

int n, m;

struct edge
{
	int u, v, w;
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
			father[f1] = f2;
			ans += edges[i].w;
		}
	}

	return ans;
}

int main()
{
	int k;
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &k);
		edges[++m] = {i, n + 1, k};
	}
	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= n ; ++j)
		{
			scanf("%d", &k);
			edges[++m] = {i, j, k};
		}
	}

	sort(edges + 1, edges + 1 + m);

	const int ans = Kruskal();
	printf("%d\n", ans);

	return 0;
}
