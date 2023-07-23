#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <vector>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
struct Graph
{
	int idx;
	int h[N], v[M], ne[M];

	Graph()
	{
		idx = 0;
		memset(h, -1, sizeof ne);
	}

	void add(int a, int b)
	{
		v[idx] = b;
		ne[idx] = h[a];
		h[a] = idx++;
	}
} g, gs;

int cnt;
int dfn[N], low[N];
int visit[N], group[N], tsize[N];

int k = 0;
stack<int> s;
void tarjan(int u)
{
	dfn[u] = low[u] = ++k;
	s.push(u);
	visit[u] = 1;

	int v;
	for (int i = g.h[u] ; i != -1 ; i = g.ne[i])
	{
		v = g.v[i];
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
			++tsize[cnt];
		} while (u != v);
	}
}

int out[N], ln;
void build()
{
	for (int i = 1 ; i <= n ; ++i)
		for (int j = g.h[i] ; j != -1 ; j = g.ne[j])
			if (group[i] != group[g.v[j]])
				gs.add(group[i], group[g.v[j]]), ++out[group[i]];
}

int eval()
{
	int ans = 0;
	for (int i = 1 ; i <= cnt ; ++i)
	{
		if (out[i] == 0)
		{
			if (ans)
				return 0;
			else
				ans = tsize[i];
		}
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d", &u, &v);
		g.add(u, v);
	}

	for (int i = 1 ; i <= n ; ++i)
		if (!dfn[i])
			tarjan(i);

	build();

	printf("%d", eval());
	return 0;
}
