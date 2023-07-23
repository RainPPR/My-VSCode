#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int MIN(const int &a, const int &b)
{
	return (a < b) ? a : b;
}

const int N = 110;

int n, m;
int g[N][N];
int l[N][N];

int way[N][N];

vector<int> dis;
void get_dis(int a, int b)
{
	if (a == b)
		return ;

	int k = way[a][b];
	if (!k)
	{
		dis.push_back(a);
		dis.push_back(b);
		return ;
	}

	get_dis(a, k);
	dis.pop_back();
	get_dis(k, b);
	return ;
}

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
	int mini, minj, mink;

	for (int k = 1 ; k <= n ; ++k)
	{
		for (int i = 1 ; i < k ; ++i)
			for (int j = i + 1 ; j < k ; ++j)
				if ((l[i][k] + l[k][j] + g[i][j]) < cmin)
				{
					cmin = l[i][k] + l[k][j] + g[i][j];
					mini = i, minj = j, mink = k;
					dis.clear();
					get_dis(mini, minj);
				}

		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= n ; ++j)
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j], way[i][j] = k;
	}

	if (cmin >= 7e8)
		printf("No solution.\n");
	else
	{
//		for (int i : dis)
		for (int k = 0 ; k < dis.size() ; ++k)
			printf("%d ", dis[k]);
		printf("%d\n", mink);
	}
	return 0;
}
