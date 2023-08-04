#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int N = 12;
const int M = N * N;

struct point
{
	int x, y;
	int key;

	int dis;

	point(int _x, int _y)
	{
		x = _x, y = _y, key = dis = 0;
	}
	point(int _x, int _y, int _key)
	{
		x = _x, y = _y, key = _key, dis = 0;
	}
	point(int _x, int _y, int _key, int _dis)
	{
		x = _x, y = _y, key = _key, dis = _dis;
	}

	bool operator == (const point &a) const
	{
		return (this->x == a.x) && (this->y == a.y) && (this->key == a.key);
	}
};
struct myHash
{
	bool operator()(const point &a) const
	{
		return (a.x << 12) | (a.y << 8) | (a.key);
	}
};

int n, m, p;
int pos[N][N];

int arr[M][M];
int key[N][N];

unordered_set<point, myHash> visit;

int main()
{
	scanf("%d %d %d", &n, &m, &p);

	do
	{
		int cnt = 0;
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= m ; ++j)
				pos[i][j] = ++cnt;
	} while (false);

	do
	{
		int k, x1, y1, x2, y2, g;
		scanf("%d", &k);
		while (k--)
		{
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &g);
			arr[pos[x1][y1]][pos[x2][y2]] = ((g == 0) ? -1 : g);
			arr[pos[x2][y2]][pos[x1][y1]] = ((g == 0) ? -1 : g);
		}
	} while (false);

	do
	{
		int s, x, y, q;
		scanf("%d", &s);
		while (s--)
		{
			scanf("%d %d %d", &x, &y, &q);
			key[x][y] |= 1 << (q - 1);
		}
	} while (false);

	int ans = 0x3f3f3f3f;
	do
	{
		queue<point> q;
		q.emplace(1, 1, key[1][1], 0);
		visit.emplace(1, 1, key[1][1]);
		while (q.size())
		{
			point t = q.front();
			q.pop();

			if (t.x == n && t.y == m)
			{
				if (t.dis < ans)
					ans = t.dis;
				continue;
			}

			int tx, ty;
			for (int i = 0 ; i < 4 ; ++i)
			{
				tx = t.x + dx[i];
				ty = t.y + dy[i];
				if (tx < 1 || tx > n || ty < 1 || ty > m)
					continue;

				int need = arr[pos[t.x][t.y]][pos[tx][ty]];
				if (need == -1)
					continue;

				if (need != 0)
					need = 1 << (need - 1);

				if (((need & t.key) == need) && !visit.count({tx, ty, t.key | key[tx][ty]}))
				{
					q.emplace(tx, ty, t.key | key[tx][ty], t.dis + 1);
					visit.emplace(tx, ty, t.key | key[tx][ty]);
				}
			}
		}
	} while (false);

	if (ans == 0x3f3f3f3f)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}
