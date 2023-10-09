#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

pair<int, int> a[N];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	int m, n, t, l, r;

	scanf("%d %d", &m, &n);
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d", &t);
		a[i] = {t, i};
	}

	sort(a + 1, a + m + 1, cmp);

	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d %d", &l, &r);
		for (int j = 1 ; j <= m ; ++j)
		{
			if ((a[j].second >= l) && (a[j].second <= r))
			{
				printf("%d ", a[j].first);
				break;
			}
		}
	}
	return 0;
}
