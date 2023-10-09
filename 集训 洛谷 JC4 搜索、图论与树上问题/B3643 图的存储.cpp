#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;

int w[N][N];
vector<int> edge[N];

int n, m;

int main()
{
	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d", &u, &v);

		w[u][v] = w[v][u] = 1;

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	for (int i = 1 ; i <= n ; ++i, putchar('\n'))
		for (int j = 1 ; j <= n ; ++j)
			printf("%d ", w[i][j]);

	for (int i = 1 ; i <= n ; ++i, putchar('\n'))
	{
		sort(edge[i].begin(), edge[i].end());
		printf("%d ", (int)edge[i].size());
		for (int j : edge[i])
			printf("%d ", j);
	}
	return 0;
}
