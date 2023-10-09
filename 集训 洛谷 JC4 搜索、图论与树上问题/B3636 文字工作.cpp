#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int dis[N];

int n;

bool isValid(int x)
{
	return x >= 1 && x <= n;
}

void bfs(int n)
{
	queue<int> q;
	q.push(0);
	
	memset(dis, 0x3f, sizeof dis);
	dis[0] = 0;
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if (now == n)
			return ;
		
		if (isValid(now + 1))
			if (dis[now] + 1 < dis[now + 1])
				dis[now + 1] = dis[now] + 1, q.push(now + 1);
		if (isValid(now * 2))
			if (dis[now] + 1 < dis[now * 2])
				dis[now * 2] = dis[now] + 1, q.push(now * 2);
	}
}

int main()
{
	scanf("%d", &n);
	bfs(n);
	printf("%d", dis[n] - 1);
	return 0;
}
