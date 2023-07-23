#include <cstdio>
#include <cstring>
#include <algorithm>
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
};

Graph g, rg;

struct Node
{
	int id, val;
	bool operator < (const Node &a) const
	{
		return this->val > a.val;
	}
} f[N];

bool visit[N];

int k;
void Kosaraju(int u)
{
	visit[u] = true;
	for (int i = g.h[u] ; i != -1 ; i = g.ne[i])
		if (!visit[g.v[i]])
			Kosaraju(g.v[i]);

	f[u].val = ++k;
}

vector<int> res[N];
void rKosaraju(int u, const int k)
{
	visit[u] = true;
	res[k].push_back(u);
	for (int i = rg.h[u] ; i != -1 ; i = rg.ne[i])
		if (!visit[rg.v[i]])
			rKosaraju(rg.v[i], k);
}

bool cmp(const vector<int> &a, const vector<int> &b)
{
	return a[0] < b[0];
}

int main()
{
	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d", &u, &v);
		g.add(u, v);
		rg.add(v, u);
	}

	for (int i = 1 ; i <= n ; ++i)
	{
		f[i].id = i;
		if (!visit[i])
			Kosaraju(i);
	}

	memset(visit, 0, sizeof visit);
	sort(f + 1, f + 1 + n);

	int ans = 0;
	for (int i = 1 ; i <= n ; ++i)
	{
		if (!visit[f[i].id])
		{
			++ans;
			rKosaraju(f[i].id, ans);
			sort(res[ans].begin(), res[ans].end());
		}
	}

	sort(res + 1, res + 1 + ans, cmp);

	printf("%d\n", ans);
	for (int i = 1 ; i <= ans ; ++i, putchar('\n'))
		for (int j : res[i])
			printf("%d ", j);

	return 0;
}
