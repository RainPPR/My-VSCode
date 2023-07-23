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

vector<int> now;
void rKosaraju(int u)
{
	visit[u] = true;
	now.push_back(u);
	for (int i = rg.h[u] ; i != -1 ; i = rg.ne[i])
		if (!visit[rg.v[i]])
			rKosaraju(rg.v[i]);
}

bool cmp(const vector<int> &a, const vector<int> &b)
{
	return a[0] < b[0];
}

int main()
{
	scanf("%d %d", &n, &m);

	int u, v, t;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &t);

		g.add(u, v);
		rg.add(v, u);
		if (t == 2)
		{
			g.add(v, u);
			rg.add(u, v);
		}
	}

	for (int i = 1 ; i <= n ; ++i)
	{
		f[i].id = i;
		if (!visit[i])
			Kosaraju(i);
	}

	memset(visit, 0, sizeof visit);
	sort(f + 1, f + 1 + n);

	vector<int> ans;
	for (int i = 1 ; i <= n ; ++i)
	{
		if (!visit[f[i].id])
		{
			now.clear();
			rKosaraju(f[i].id);
			if (now.size() >= ans.size())
			{
				sort(now.begin(), now.end());
				if (now.size() > ans.size())
					ans = now;
				else if (now < ans)
					ans = now;
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i : ans)
		printf("%d ", i);

	return 0;
}
