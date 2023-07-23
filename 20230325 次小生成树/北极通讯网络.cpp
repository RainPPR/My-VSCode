#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 510;
const int M = N * (N - 1) / 2;

struct point
{
	int x, y;
} vils[N];

int get_w2(point a, point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct edge
{
	int u, v;
	int w;
	bool operator < (const edge &a) const
	{
		return this->w < a.w;
	}
} edges[M];

int n, m, k;

int father[N];
int find(int x)
{
	if (x == father[x])
		return x;
	father[x] = find(father[x]);
	return father[x];
}

int Kruskral(int target)
{
	for (int i = 1 ; i <= n ; ++i)
		father[i] = i;

	int res = -2e9, cnt = 0;
	for (int i = 1 ; i <= m ; ++i)
	{
		const int f1 = find(edges[i].u), f2 = find(edges[i].v);
		if (f1 != f2)
		{
			father[f1] = f2;
			if (edges[i].w > res)
				res = edges[i].w;
			if (++cnt >= target)
				return res;
		}
	}

	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d %d", &vils[i].x, &vils[i].y);

	for (int i = 1 ; i <= n ; ++i)
		for (int j = i + 1 ; j <= n ; ++j)
			edges[++m] = {i, j, get_w2(vils[i], vils[j])};

	sort(edges + 1, edges + 1 + m);

	double ans = 0;
	if (n != k)
		ans = sqrt(Kruskral(n - k));
	printf("%.2lf\n", ans);

	return 0;
}
