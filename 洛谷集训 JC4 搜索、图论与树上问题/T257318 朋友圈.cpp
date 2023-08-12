#include <cstdio>

using namespace std;

const int N = 1010;

int w[N][N];

int n, m;

int main()
{
	scanf("%d %d", &n, &m);

	int u, v;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d", &u, &v);
		w[u][v] = w[v][u] = 1;
	}

	for (int i = 1 ; i <= n ; ++i)
	{
		int cnt = 0;
		for (int j = 1 ; j <= n ; ++j)
			if (w[i][j])
				++cnt;
		printf("%d\n", cnt);
	}
	return 0;
}
