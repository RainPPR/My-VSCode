#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100, M = N * (N - 1);

int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
	if (!b)
		return ;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

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

int main()
{
	int n, u, v;
	char c;
	string vt;
	while (cin >> n && n)
	{
		idx = 0;
		cnt = 0;
		memset(h, -1, sizeof h);
		memset(dfn, 0, sizeof dfn);
		memset(is, 0, sizeof is);

		while (cin >> u && u)
		{
			getline(cin, vt);

			v = 0;
			for (int i = 0 ; i < vt.size() ; ++i)
			{
				c = vt[i];
				if (c == ' ')
					add(u, v), add(v, u), v = 0;
				else if (c >= '0' && c <= '9')
					v = v * 10 + int(c - '0');
			}
			add(u, v);
			add(v, u);
		}

		tarjan(1);

		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (is[i])
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
