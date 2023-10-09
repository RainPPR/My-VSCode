#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
char a[N][N];

bool vis[N][N];

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '0' && !vis[x][y];
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({x, y});

	while (!q.empty())
	{
		x = q.front().first, y = q.front().second;
		q.pop();

		vis[x][y] = 1;
		a[x][y] = '0';

		for (int i = 0 ; i < 4 ; ++i)
			if (isValid(x + dx[i], y + dy[i]))
				q.push({x + dx[i], y + dy[i]});
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%s", a[i] + 1);

	int cnt = 0;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			if (a[i][j] != '0')
				memset(vis, 0, sizeof vis), bfs(i, j), ++cnt;

	printf("%d", cnt);
	return 0;
}
