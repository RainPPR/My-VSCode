#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

vector<int> edge[N];

int n, m;

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

	for (int i = 1 ; i <= n ; ++i)
		printf("%d\n", (int)edge[i].size());
	return 0;
}
