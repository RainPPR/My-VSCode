#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

struct node
{
	int x, y;
	int mx, my;
};

char mp[N][N];
bool vis[N][N];

int main()
{
	int n, m, r, c, x, y;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &r, &c);
	scanf("%d %d", &x, &y);
	
	for (int i = 1 ; i <= n ; ++i)
		scanf("%s", mp[i] + 1);

	deque<node> q;
	q.push_front({r, c, x, y});
	
	int cnt = 0;
	while (q.size())
	{
		node now = q.front();
		q.pop_front();
		
		x = now.x;
		y = now.y;
		
		if (vis[x][y])
			continue;
		vis[x][y] = true;
		++cnt;
		
		if (x + 1 <= n && mp[x + 1][y] == '.')
			q.push_front({x + 1, y, now.mx, now.my});
		if (x - 1 >= 1 && mp[x - 1][y] == '.')
			q.push_front({x - 1, y, now.mx, now.my});
		if (y - 1 >= 1 && mp[x][y - 1] == '.' && now.mx)
			q.push_back({x, y - 1, now.mx - 1, now.my});
		if (y + 1 <= m && mp[x][y + 1] == '.' && now.my)
			q.push_back({x, y + 1, now.mx, now.my - 1});
	}
	
	printf("%d\n", cnt);
	return 0;
}
