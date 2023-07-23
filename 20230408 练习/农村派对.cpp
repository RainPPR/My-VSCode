#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = 1e4 + 10;
const int INF = 1e9;

int n, m, x;

struct Graph
{
	int n, m;
	int h[N], v[M], d[M], ne[M], idx;

	Graph()
	{
		idx = 0;
		memset(h, -1, sizeof h);
	}

	void add(int a, int b, int c)
	{
		v[idx] = b;
		d[idx] = c;
		ne[idx] = h[a];
		h[a] = idx++;
	}

	int dist[N];
	bool vis[N];
	void dijkstra(int st)
	{
		memset(dist, 0x3f, sizeof dist);
		dist[st] = 0;

		priority_queue<PII, vector<PII>, greater<PII>> heap;
		heap.push(make_pair(0, st));

		while (heap.size())
		{
			PII t = heap.top();
			heap.pop();

			int b = t.second, c = t.first;
			if (vis[b])
				continue;
			vis[b] = true;

			for (int i = h[b] ; i != -1 ; i = ne[i])
			{
				int j = v[i];
				if (dist[j] > c + d[i])
				{
					dist[j] = c + d[i];
					heap.push(make_pair(dist[j], j));
				}
			}
		}

		return ;
	}
} g, rg;

int main()
{
	scanf("%d %d %d", &n, &m, &x);

	int a, b, t;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &a, &b, &t);
		g.add(a, b, t);
		rg.add(b, a, t);
	}

	g.dijkstra(x);
	rg.dijkstra(x);

	int cmax = -2e9;
	for (int i = 1 ; i <= n ; ++i)
		cmax = max(cmax, g.dist[i] + rg.dist[i]);
	printf("%d\n", cmax);

	return 0;
}

