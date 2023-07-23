#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;
const int M = N * (N - 1) / 2;
const int MOD = (1 << 31) - 1;

int n, m;

int h[N], w[M], e[M], ne[M], idx;

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dis[N];
bool vis[N];

void dijkstra()
{
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;

	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});

	while (heap.size())
	{
		int v = heap.top().second, d = heap.top().first;
		heap.pop();

		if (vis[v])
			continue;
		vis[v] = true;

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

int cnt[N];

int main()
{
	memset(h, -1, sizeof h);

	scanf("%d %d", &n, &m);
	int u, v, c;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &c);
		add(u, v, c);
		add(v, u, c);
	}

	dijkstra();

	for (int i = 1 ; i <= n ; ++i)
		for (int j = h[i] ; j != -1 ; j = ne[j])
			if (dis[i] + w[j] == dis[e[j]])
				++cnt[e[j]];

	long long ans = 1;
	for (int i = 2; i <= n; ++i)
		ans = ans * cnt[i] % MOD;

	printf("%lld", ans);
	return 0;
}
