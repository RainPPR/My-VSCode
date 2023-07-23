#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m, x;

struct Graph
{
	int h[N], e[M], ne[M];
	int idx;

	Graph()
	{
		memset(h, -1, sizeof h);
		idx = 0;
	}

	void add(int u, int v)
	{
		e[idx] = v;
		ne[idx] = h[u];
		h[u] = idx++;
	}
} g, gs;

int k, cnt;
int dfn[N], low[N];
int visit[N], group[N], tsize[N];

stack<int> s;
void Tarjan(int u)
{
	dfn[u] = low[u] = ++k;
	s.push(u);
	visit[u] = 1;

	int v;
	for (int i = g.h[u] ; i != -1 ; i = g.ne[i])
	{
		v = g.e[i];
		if (!dfn[v])
		{
			Tarjan(v);
			dfn[u] = min(dfn[u], dfn[v]);
		}
		else if (visit[v])
			dfn[u] = min(dfn[u], dfn[v]);
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

int in[N];
set<pair<int, int>> uni;
void build()
{
	for (int i = 1 ; i <= n ; ++i)
		for (int j = g.h[i] ; j != -1 ; j = g.ne[j])
			if (group[i] != group[g.e[j]] && uni.count(make_pair(group[i], group[g.e[j]])) == 0)
				gs.add(group[i], group[g.e[j]]), ++in[group[g.e[j]]], uni.insert(make_pair(group[i], group[g.e[j]]));
}

int height[N], dp[N];
int calc()
{
	queue<int> q;
	for (int i = 1 ; i <= cnt ; ++i)
		if (!in[i])
			q.emplace(i), height[i] = dp[i] = 1;

	int ans = 1;
	while (q.size())
	{
		int t = q.front();
		q.pop();

		for (int i = gs.h[t] ; i != -1 ; i = gs.ne[i])
		{
			int j = gs.e[i];

			dp[j] = dp[t] * tsize[j];
			height[j] = height[t] + 1;
			ans = max(ans, height[j]);

			if (--in[j] == 0)
				q.emplace(j);
		}
	}

	return ans;
}

int main()
{
	scanf("%d %d %d", &n, &m, &x);

	int u, v;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d", &u, &v);
		g.add(u, v);
	}

	for (int i = 1 ; i <= n ; ++i)
		if (!dfn[i])
			Tarjan(i);

	build();

	int ans = calc();
	printf("%d\n", ans);

	int res = 0;
	for (int i = 1 ; i <= cnt ; ++i)
		if (height[i] == ans)
			res += dp[i];
	printf("%d\n", res);
	return 0;
}
