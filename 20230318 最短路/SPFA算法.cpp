#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
const int M = 5e5 + 10;

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

void SPFA(int s)
{
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;

	queue<int> q;
	q.push(s);
	st[s] = true;

	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;

		for (int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dis[j] > dis[t] + w[i])
			{
				dis[j] = dis[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);

	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);

	unordered_map<int, int> dist[N];

	int u, v, d;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &d);
		if (dist[u].count(v))
			dist[u][v] = min(dist[u][v], d);
		else
			dist[u][v] = d;
	}

	for (int i = 1 ; i <= n ; ++i)
		for (pair<int, int> j : dist[i])
			add(i, j.first, j.second);

	SPFA(s);

	for (int i = 1 ; i <= n ; ++i)
	{
		if (dis[i] == 0x3f3f3f3f)
			dis[i] = 2147483647;
		printf("%d ", dis[i]);
	}
	return 0;
}
