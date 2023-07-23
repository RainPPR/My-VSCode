#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#define int long long

using namespace std;

const int N = 1050;

// 邻接表

int h[N], e[N], ne[N], idx;

void add(int u, int v)
{
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx++;
}

// Tarjan

int dfn[N], low[N], cnt;
bool is[N];

void tarjan(int u)
{
	dfn[u] = low[u] = ++cnt;

	int cc = 0;
	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		int v = e[i];
		if (!dfn[v])
		{
			++cc;
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (u != 1 && dfn[u] <= low[v])
				is[u] = true;
		}
		else
			low[u] = min(low[u], dfn[v]);
	}

	if (u == 1 && cc > 1)
		is[u] = true;
}

// 并查集

int f[N], size[N];

int find(int x)
{
	if (x == f[x])
		return x;
	return x = find(f[x]);
}

void merge(int u, int v)
{
	u = find(u), v = find(v);
	if (u == v)
		return ;
	size[v] += size[u];
	f[u] = v;
}

// 建图

int s1, s2;
void build(const int &n)
{
	for (int i = 1 ; i <= n ; ++i)
		if (!is[i])
			for (int j = h[i] ; j != -1 ; j = ne[j])
				if (!is[e[j]])
					merge(i, e[j]);

	s1 = 0, s2 = 1;
	for (int i = 1 ; i <= n ; ++i)
		if (!is[i] && i == f[i])
			++s1, s2 *= size[i];
}

// Main

signed main()
{
	int cc = 0, n, m, u, v;
	while (cin >> m && m)
	{
		memset(h, -1, sizeof h);
		n = idx = 0;

		for (int i = 0 ; i < m ; ++i)
		{
			scanf("%lld %lld", &u, &v);
			n = max(n, max(u, v));
			add(u, v);
			add(v, u);
		}

		memset(dfn, 0, sizeof dfn);
		memset(is, 0, sizeof is);
		cnt = 0;
		for (int i = 1 ; i <= n ; ++i)
		{
			f[i] = i;
			size[i] = 1;
			if (!dfn[i])
				tarjan(i);
		}

		build(n);

		printf("Case %lld: %lld %lld\n", ++cc, s1, s2);
		
		cout << n << " " << m << endl;
		for (int i = 1 ; i <= n ; ++i)
			printf("%d ", is[i]);
		putchar('\n');
		for (int i = 1 ; i <= n ; ++i)
			printf("%lld ", find(i));
		putchar('\n');
		for (int i = 1 ; i <= n ; ++i)
			printf("%lld ", size[find(i)]);
		putchar('\n');
		
	}
	return 0;
}
