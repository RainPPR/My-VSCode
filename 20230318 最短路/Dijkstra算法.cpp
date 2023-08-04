#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> PII;

const int INF = 2147483647;
const int N = 1e5 + 10;
const int M = 5e5 + 10;

int n, m;

int h[N], e[M], w[M], ne[M], idx;

void add(int u, int v, int d)
{
	e[idx] = v;
	w[idx] = d;
	ne[idx] = h[u];
	h[u] = idx++;
}

int dis[N];
bool st[N];

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;

	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, s});

	while (heap.size())
	{
		int v = heap.top().second, d = heap.top().first;
		heap.pop();

		if (st[v])
			continue;
		st[v] = true;

		for (int i = h[v] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dis[j] > d + w[i])
			{
				dis[j] = d + w[i];
				heap.push({dis[j], j});
			}
		}
	}
}

unordered_map<int, int> dist[N];

int main()
{
	memset(h, -1, sizeof(h));

	int s;
	scanf("%d %d %d", &n, &m, &s);

	int u, v, w;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		if (dist[u].count(v))
			dist[u][v] = min(dist[u][v], w);
		else
			dist[u][v] = w;
	}

	for (int i = 1 ; i <= n ; ++i)
		for (PII j : dist[i])
			add(i, j.first, j.second);

	dijkstra(s);

	for (int i = 1 ; i <= n ; ++i)
	{
		if (dis[i] == 0x3f3f3f3f)
			dis[i] = INF;
		printf("%d ", dis[i]);
	}
	return 0;
}
