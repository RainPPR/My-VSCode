#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 510, M = 10010;

int n, m;

struct Edge
{
	int a, b, w;
	bool f;
	bool operator < (const Edge &t) const
	{
		return w < t.w;
	}
} edge[M];

int p[N];
int dist1[N][N], dist2[N][N];
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx;

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[])
{
	d1[u] = maxd1, d2[u] = maxd2;
	for (int i = h[u] ; ~i ; i = ne[i])
	{
		int j = e[i];
		if (j != fa)
		{
			int td1 = maxd1, td2 = maxd2;
			if (w[i] > td1)
				td2 = td1, td1 = w[i];
			else if (w[i] < td1 && w[i] > td2)
				td2 = w[i];
			dfs(j, u, td1, td2, d1, d2);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 0 ; i < m ; i ++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		edge[i] = {a, b, w};
	}

	sort(edge, edge + m);

	for (int i = 1 ; i <= n ; i ++)
		p[i] = i;

	ll sum = 0;
	for (int i = 0 ; i < m ; i ++)
	{
		int a = edge[i].a, b = edge[i].b, w = edge[i].w;
		int pa = find(a), pb = find(b);
		if (pa != pb)
		{
			p[pa] = pb;
			sum += w;
			add(a, b, w);
			add(b, a, w);
			edge[i].f = true;
		}
	}

	for (int i = 1 ; i <= n ; i ++)
		dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]);

	ll res = 1e18;
	for (int i = 0; i < m; i ++)
	{
		if (!edge[i].f)
		{
			int a = edge[i].a, b = edge[i].b, w = edge[i].w;
			ll t;
			if (w > dist1[a][b])
				t = sum + w - dist1[a][b];
			else if (w > dist2[a][b])
				t = sum + w - dist2[a][b];
			res = min(res, t);
		}
	}

	printf("%lld\n", res);
	return 0;
}
