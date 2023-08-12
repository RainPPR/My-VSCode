#include <cstdio>
#include <vector>

using namespace std;

const int N = 1010;

int n, q;
int dad[N];

vector<int> edge[N];

int vis[N];
void dfs(int x)
{
	vis[x] = 1;
	for (int p : edge[x])
	{
		if (!vis[p])
		{
			dad[p] = x;
			dfs(p);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	
	int x, y;
	for (int i = 1 ; i <= n - 1 ; ++i)
	{
		scanf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	dfs(1);
	
	while (q--)
	{
		scanf("%d %d", &x, &y);
		
		bool ans = false;
		for (int p : edge[x])
			if (p != dad[x] && p == y)
				ans = true;
		
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
