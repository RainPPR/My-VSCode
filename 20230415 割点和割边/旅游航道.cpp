#include <iostream>
#include <cstring>

using namespace std;

const int N = 15010, M = N * (N - 1);

int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dfn[N], low[N], cnt, ans;

void tarjan(int u)
{
	dfn[u] = low[u] = ++cnt;
	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		int v = e[i];
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
				++ans;
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}

int main()
{

	int m, n;
	while (cin >> m >> n && m)
	{
		cnt = ans = idx = 0;
		memset(h, -1, sizeof h);
		memset(dfn, 0, sizeof dfn);

		int u, v;
		for (int i = 1 ; i <= n ; ++i)
		{
			scanf("%d %d", &u, &v);
			add(u, v), add(u, v);
		}

		tarjan(1);

		printf("%d\n", ans);
	}

	return 0;
}
