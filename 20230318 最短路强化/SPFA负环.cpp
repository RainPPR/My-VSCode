#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2e3 + 10;
const int M = 6e3 + 10;

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
int cnt[N];

int SPFA(int n)
{
	memset(dis, 0x3f, sizeof dis);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	dis[1] = 0;

	queue<int> q;

	q.push(1);
	st[1] = true;

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
					if (++cnt[j] >= n)
						return 1;

					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);

	int n, m;
	int u, v, d;
	while (T--)
	{
		memset(h, -1, sizeof h);
		idx = 0;

		scanf("%d %d", &n, &m);
		for (int i = 1 ; i <= m ; ++i)
		{
			scanf("%d %d %d", &u, &v, &d);
			add(u, v, d);
			if (d >= 0)
				add(v, u, d);
		}

		int flag = SPFA(n);

		printf(flag ? "YES\n" : "NO\n");
	}
	return 0;
}
