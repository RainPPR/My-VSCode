#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

vector<int> edge[N];

int n, m;

int vis[N];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		vis[now] = 1;
		
		for (int p : edge[now])
			if (!vis[p])
				q.push(p);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	int u, v;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d", &u, &v);
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	// flood fill
	bfs(1);
	printf(vis[n] ? "Yes" : "No");
	return 0;
}
