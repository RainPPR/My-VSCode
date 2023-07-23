#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

const int N = 1e5 + 10, M = 3e5 + 10;

int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dfn[N], low[N], cnt, root;
stack<int> st;
vector<int> dcc[N];

void tarjan(int u)
{
	dfn[u] = low[u] = ++cnt;
	st.push(u);
	if (u == root && h[u] == -1)
	{
		dcc[++cnt].push_back(u);
		return ;
	}
	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		int v = e[i];
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u])
			{
				++cnt;
				int t;
				do
				{
					t = st.top();
					st.pop();
					dcc[cnt].push_back(t);
				} while (t != v);
				dcc[cnt].push_back(u);
			}
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}

int main()
{
	memset(h, -1, sizeof h);

	int n, m, u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
	}

	for (int i = 1 ; i <= n ; ++i)
	{
		if (!dfn[i])
		{
			root = i;
			tarjan(i);
		}
	}

	for (int i = 1 ; i <= cnt ; i++)
	{
		bool isout = false;
		for (int j = 0 ; j < dcc[i].size() ; j++)
			printf("%d ", dcc[i][j]), isout = true;
		if (isout)
			putchar('\n');
	}
	return 0;
}
