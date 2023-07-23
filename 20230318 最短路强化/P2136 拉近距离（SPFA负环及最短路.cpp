#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e3 + 10;
const int M = 1e4 + 10;

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
int cnt[N];

int SPFA(int l, int r)
{
	memset(dis, 0x3f, sizeof dis);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	dis[l] = 0;

	queue<int> q;

	q.push(l);
	st[l] = true;

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
						return 0x3f3f3f3f;

					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	return dis[r];
}

int main()
{
	memset(h, -1, sizeof h);

	scanf("%d %d", &n, &m);

	int u, v, d;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &d);
		add(u, v, -d);
	}

	int s1 = SPFA(1, n);
	int s2 = SPFA(n, 1);

	int ans = min(s1, s2);
	if (ans == 0x3f3f3f3f)
		printf("Forever love\n");
	else
		printf("%d\n", ans);
	return 0;
}
