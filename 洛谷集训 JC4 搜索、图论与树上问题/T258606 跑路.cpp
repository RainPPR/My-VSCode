#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

vector<int> edge[N];

int n, m;

int vis[N];

void dfs(int x)
{
	if (vis[x])
		return;
	vis[x] = 1;
	
	for (int p:edge[x])
		dfs(p);
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
	dfs(1);
	printf(vis[n] ? "Yes" : "No");
	return 0;
}
