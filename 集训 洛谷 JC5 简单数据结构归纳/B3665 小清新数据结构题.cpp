#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e6 + 10;

vector<unsigned int> a[N];

int main()
{
	int n, q, s;
	unsigned int t;

	scanf("%d %d", &n, &q);
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d", &s);
		for (int j = 0 ; j < s ; ++j)
		{
			scanf("%u", &t);
			a[i].push_back(t);
		}
	}

	int x, y;
	unsigned int ans = 0;
	for (int i = 1 ; i <= q ; ++i)
	{
		scanf("%d %d", &x, &y);
		ans ^= a[x - 1][y - 1];
	}

	printf("%u", ans);
	return 0;
}
