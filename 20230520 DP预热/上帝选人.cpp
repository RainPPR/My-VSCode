#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N = 5e6 + 10;

int n;

struct _A
{
	int iq, eq;

	_A()
	{
		iq = eq = 0;
	}
	_A(int _i, int _e)
	{
		iq = _i, eq = _e;
	}

	bool operator < (const _A &t)
	{
		return (iq == t.iq) ? (eq < t.eq) : (iq < t.iq);
	}
} e[N];

int dp[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d %d", &e[i].iq, &e[i].eq);

	sort(e + 1, e + 1 + n);

	int ans = -1;
	for (int i = 1 ; i <= n ; ++i)
	{
		dp[i] = 1;

		for (int j = 1 ; j < i ; ++j)
			if (e[i].eq >= e[j].eq && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;

		if (dp[i] > ans)
			ans = dp[i];
	}

	printf("%d\n", ans);
	return 0;
}
