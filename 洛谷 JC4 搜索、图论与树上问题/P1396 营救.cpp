#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

vector<pair<int, int>> edge[N];

int n, m, s, t;

bool check(int x)
{
	queue<int> q;
	q.push(s);

	while (q.size())
	{
		int now = q.front();
		q.pop();

		if (now == t)
			return true;

		for (pair<int, int> i : edge[now])
			if (i.second <= x)
				q.push(i.first);
	}

	return false;
}

int main()
{
	int l = 0, r = -2e9;

	int u, v, w;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
		r = (w > r) ? w : r;
	}

	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}

	printf("%d", l);
	return 0;
}
