#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

vector<pair<int, int>> edge[N];

int n, m;

int main()
{
	scanf("%d %d", &n, &m);

	int u, v, x;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &x);
		edge[u].push_back({v, x});
	}

	for (int i = 1 ; i <= n ; ++i)
	{
		int cnt = 0;
		for (pair<int, int> j : edge[i])
			cnt += j.second;
		printf("%d\n", cnt);
	}
	return 0;
}
