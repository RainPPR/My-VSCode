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

const int N = 1010, M = N * (N - 1) / 2, L = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int n, p, k;

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

	void d_add(int a, int b, int c)
	{
		add(a, b, c);
		add(b, a, c);
	}
} g, eg;

int dist[N];
bool vis[N];
int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	dist[1] = 0;

	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push(make_pair(0, 1));

	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();

		int b = t.second, c = t.first;
		if (vis[b])
			continue;
		vis[b] = true;

		for (int i = eg.h[b] ; i != -1 ; i = eg.ne[i])
		{
			int j = eg.v[i];
			if (dist[j] > c + eg.d[i])
			{
				dist[j] = c + eg.d[i];
				heap.push(make_pair(dist[j], j));
			}
		}
	}
	return dist[n];
}

bool check(const int &x)
{
	eg = Graph();

	for (int i = 1 ; i <= n ; ++i)
		for (int j = g.h[i] ; j != -1 ; j = g.ne[j])
			eg.d_add(g.v[j], i, g.d[j] > x);

	return dijkstra() <= k;
}

int calc()
{
	int l = 0, r = L, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	return (l == L) ? -1 : l;
}

int main()
{
	scanf("%d %d %d", &n, &p, &k);

	int a, b, d;
	for (int i = 0 ; i < p ; ++i)
	{
		scanf("%d %d %d", &a, &b, &d);
		g.d_add(a, b, d);
	}

	printf("%d\n", calc());
	return 0;
}

