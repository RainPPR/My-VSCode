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
int l[N][N];

int main()
{
	for (int i = 0 ; i < N ; ++i)
		for (int j = 0 ; j < N ; ++j)
			if (i != j)
				l[i][j] = g[i][j] = 7e8;
	
	int u, v, w;
	scanf("%d %d", &n, &m);
	
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		
		if (w < l[u][v])
			l[u][v] = g[u][v] = w;
		if (w < l[v][u])
			l[v][u] = g[v][u] = w;
	}
	
	int cmin = 2e9;
	
	for (int k = 1 ; k <= n ; ++k)
	{
		for (int i = 1 ; i < k ; ++i)
			for (int j = i + 1 ; j < k ; ++j)
				cmin = MIN(cmin, l[i][k] + l[k][j] + g[i][j]);
		
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= n ; ++j)
				g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);
	}
	
	if (cmin >= 7e8)
		printf("No solution.\n");
	else
		printf("%d\n", cmin);
	return 0;
}
