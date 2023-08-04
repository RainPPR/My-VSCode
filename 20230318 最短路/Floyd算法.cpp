#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int MIN(const int &a, const int &b)
{
	return (a < b) ? a : b;
}

const int N = 110;

int n, m;
int g[N][N];

int main()
{
	for (int i = 0 ; i < N ; ++i)
		for (int j = 0 ; j < N ; ++j)
			if (i != j)
				g[i][j] = 7e8;

	int u, v, w;
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		g[u][v] = MIN(g[u][v], w);
		g[v][u] = MIN(g[v][u], w);
	}

	for (int k = 1 ; k <= n ; ++k)
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= n ; ++j)
				g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);

	for (int i = 1 ; i <= n ; ++i, putchar('\n'))
		for (int j = 1 ; j <= n ; ++j)
			printf("%d ", g[i][j]);

	return 0;
}
