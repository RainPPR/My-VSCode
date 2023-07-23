#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

const int N = 110;
const int M = 1010;
const int MOD = 31011;

int n, m;

struct edge
{
	int u, v, w;
	bool used;
	bool operator < (const edge &a) const
	{
		return this->w < a.w;
	}
} edges[M];

int father[N];
int find(int x)
{
	if (x == father[x])
		return x;
	father[x] = find(father[x]);
	return father[x];
}

unordered_map<int, int> cnt;

int ans = 1;

void Kruskal()
{
	for (int i = 1 ; i <= n ; ++i)
		father[i] = i;

	for (int i = 1 ; i <= m ; ++i)
	{
		const int f1 = find(edges[i].u), f2 = find(edges[i].v);

		if (f1 != f2)
		{
			edges[i].used = true;
			cout << edges[i].u << " -> " << edges[i].v << ": " << edges[i].w << "]; " << cnt[edges[i].w] << endl;
			ans = (ans * (1 << cnt[edges[i].w])) % MOD;
			++cnt[edges[i].w];
			father[f1] = f2;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		edges[i].used = false;
	}

	sort(edges + 1, edges + 1 + m);

	Kruskal();
	printf("%d\n", ans);

	return 0;
}
