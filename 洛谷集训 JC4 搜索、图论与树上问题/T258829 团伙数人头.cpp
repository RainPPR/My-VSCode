#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

vector<int> child[N];
int ans[N];

int dfs(int x)
{
	int cnt = 1;
	for (int i : child[x])
		cnt += dfs(i);

	ans[x] = cnt;
	return cnt;
}

int main()
{
	int n, u, v;

	scanf("%d", &n);
	for (int i = 1 ; i <= n - 1 ; ++i)
	{
		scanf("%d %d", &u, &v);
		child[v].push_back(u);
	}

	dfs(1);

	for (int i = 1 ; i <= n ; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
