#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int N = 10010, M = 30010;

int h[N], e[M], ne[M], idx;

void add(int u, int v)
{
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx++;
}

int dfn[N], low[N], cnt, root;
int belong[N], ans;

stack<int> gs;

void tarjan(int u)
{
	dfn[u] = low[u] = ++cnt;

	gs.push(u);
	if (u == root && h[u] == -1)
	{
		ans = max(ans, ++belong[u]);
		return;
	}

	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		int v = e[i];
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] <= dfn[u])
			{
				int t;
				do
				{
					t = gs.top();
					gs.pop();
					ans = max(ans, ++belong[t]);
				} while (t != v);
				ans = max(ans, ++belong[u]);
			}
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}

int f[N], fsize;

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
	--fsize;
	f[u] = v;
}

int main()
{
	const stack<int> EMPTY;
	int n, m;
	while (cin >> n >> m && n)
	{
		if (m == 0)
		{
			printf("%d\n", n - 1);
			continue;
		}

		idx = 0;
		memset(h, -1, sizeof h);

		fsize = n;
		for (int i = 0 ; i < n ; ++i)
			f[i] = i;

		int u, v;
		for (int i =  0; i < m ; ++i)
		{
			scanf("%d %d", &u, &v);
			add(u, v);
			add(u, v);
			merge(u, v);
		}

		cnt = 0;
		ans = 1;
		memset(dfn, 0, sizeof dfn);
		memset(belong, 0, sizeof belong);
		gs = EMPTY;

		for (int i = 0 ; i < n ; ++i)
			if (!dfn[i])
				root = i, tarjan(i);

		ans += fsize - 1;
		printf("%d\n", ans);

		for (int i = 0 ; i < n ; ++i)
			printf("%d ", belong[i]);
		putchar('\n');
	}
	return 0;
}
