#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 160;

int main()
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);

	vector<int> edge[N];
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	vector<pair<int, int>> ans;
	for (int i = 1 ; i <= n ; ++i)
	{
		if (edge[i].size() == 1)
		{
			if (i < edge[i][0])
				ans.push_back({i, edge[i][0]});
			else
				ans.push_back({edge[i][0], i});
		}
	}

	sort(ans.begin(), ans.end());
	for (pair<int, int> i : ans)
		printf("%d %d\n", i.first, i.second);

	return 0;
}
