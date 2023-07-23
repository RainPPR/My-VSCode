#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <vector>

using namespace std;

const int N = 5010, M = 50010;

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
		{
			low[u] = min(low[u], low[v[i]]);
		}
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

	int u, v, t;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &t);

		add(u, v);
		if (t == 2)
			add(v, u);
	}

	for (int i = 1 ; i <= n ; ++i)
		if (!dfn[i])
			tarjan(i);

	vector<int> now, ans;
	for (int i = 1 ; i <= cnt ; ++i)
	{
		now.clear();

		for (int j = 1 ; j <= n ; ++j)
			if (group[j] == i)
				now.push_back(j);

		if (now.size() >= ans.size())
		{
			if (now.size() > ans.size())
				ans = now;
			else if (now < ans)
				ans = now;
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i : ans)
		printf("%d ", i);

	return 0;
}
