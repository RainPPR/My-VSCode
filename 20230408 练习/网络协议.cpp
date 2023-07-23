#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

constexpr int N = 110, M = N * (N - 1) / 2;

int n;

int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int cnt;
int dfn[N], low[N];
int visit[N], group[N], size[N];

int k = 0;
stack<int> s;
void tarjan(int u)
{
	dfn[u] = low[u] = ++k;
	s.push(u);
	visit[u] = 1;

	int v;
	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		v = e[i];
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (visit[v])
			low[u] = min(low[u], low[v]);
	}

	if (dfn[u] == low[u])
	{
		++cnt;
		do
		{
			v = s.top();
			s.pop();
			visit[v] = 0;
			group[v] = cnt;
			++size[cnt];
		} while (u != v);
	}
}

int count_in[N], count_out[N];

int ln;
void build()
{
	for (int i = 1 ; i <= n ; ++i)
		for (int j = h[i] ; j != -1 ; j = ne[j])
			if (group[i] != group[e[j]])
				++ln, ++count_in[group[e[j]]], ++count_out[group[i]];
}

int main()
{
	memset(h, -1, sizeof h);

	int t;
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &t);
		while (t)
		{
			add(i, t);
			scanf("%d", &t);
		}
	}

	for (int i = 1 ; i <= n ; ++i)
		if (!dfn[i])
			tarjan(i);

	build();

	int cic = 0, coc = 0;
	for (int i = 1 ; i <= ln ; ++i)
	{
		if (count_in[i] == 0)
			++cic;
		if (count_out[i] == 0)
			++coc;
	}

	printf("%d\n%d\n", cic, coc);
	return 0;
}
