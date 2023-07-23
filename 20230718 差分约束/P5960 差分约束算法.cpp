#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, m;
int h[N], e[N], w[N], ne[N], idx;

int dis[N];
int cnt[N];
bool st[N];

void add(int u, int v, int x)
{
	e[idx] = v;
	w[idx] = x;
	ne[idx] = h[u];
	h[u] = idx++;
}

bool spfa(int x)
{
	memset(dis, 0x3f, sizeof dis);
	dis[x] = 0;

	queue<int> q;
	q.push(x);
	st[x] = true;
	cnt[x] = 1;

	while (q.size())
	{
		int u = q.front();
		q.pop();
		st[u] = false;

		for (int i = h[u] ; i != -1 ; i = ne[i])
		{
			int v = e[i];
			if (dis[v] > dis[u] + w[i])
			{
				dis[v] = dis[u] + w[i];
				if (!st[v])
				{
					if (++cnt[v] > n + 1)
						return true;
					q.push(v);
					st[v] = true;
				}
			}
		}
	}

	return false;
}

int main()
{
	memset(h, -1, sizeof h);

	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= m ; ++i)
	{
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		add(b, a, x);
	}

	for (int i = 1 ; i <= n ; ++i)
		add(0, i, 0);

	if (spfa(0))
		printf("NO\n");
	else
		for (int i = 1 ; i <= n ; ++i)
			printf("%d ", dis[i]);

	return 0;
}
