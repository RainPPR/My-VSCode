#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <vector>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
int h[N], v[M], ne[M], idx;

void add(int a, int b)
{
	v[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int cnt;
int dfn[N], low[N];
int visit[N], group[N];

int k = 0;
stack<int> s;
void tarjan(int u)
{
	dfn[u] = low[u] = ++k;
	s.push(u);
	visit[u] = 1;

	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		if (!dfn[v[i]])
		{
			tarjan(v[i]);
			low[u] = min(low[u], low[v[i]]);
		}
		else if (visit[v[i]])
			low[u] = min(low[u], low[v[i]]);
	}

	if (dfn[u] == low[u])
	{
		++cnt;
		int v;
		do
		{
			v = s.top();
			s.pop();
			visit[v] = 0;
			group[v] = cnt;
		} while (u != v);
	}
}

int main()
{
	memset(h, -1, sizeof h);

	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}

	for (int i = 1 ; i <= n ; ++i)
		if (!dfn[i])
			tarjan(i);

	int k, t;
	map<int, vector<int>> ans;
	for (int i = 1 ; i <= cnt ; ++i)
	{
		for (k = 1 ; k <= n ; ++k)
			if (group[k] == i)
				break;

		t = k;

		while (k <= n)
		{
			if (group[k] == i)
				ans[t].push_back(k);
			++k;
		}
	}

	printf("%d\n", cnt);
	for (pair<int, vector<int>> i : ans)
	{
		for (int j : i.second)
			printf("%d ", j);
		putchar('\n');
	}
	return 0;
}
