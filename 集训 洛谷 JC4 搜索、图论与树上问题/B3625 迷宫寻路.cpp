#include <cstdio>

using namespace std;

const int N = 110;

int n, m;
char a[N][N];

int vis[N][N];

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m || a[x][y] != '.' || vis[x][y])
		return ;
	vis[x][y] = 1;

	for (int i = 0 ; i < 4 ; ++i)
		dfs(x + dx[i], y + dy[i]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%s", a[i] + 1);

	dfs(1, 1);
	printf(vis[n][m] ? "Yes" : "No");
	return 0;
}
