#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

vector<int> m = {1, 5, 11};

int dis[N];

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

		for (int i : m)
			if (dis[now] + 1 < dis[now + i])
				dis[now + i] = dis[now] + 1, q.push(now + i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	bfs(n);
	printf("%d", dis[n]);
	return 0;
}
