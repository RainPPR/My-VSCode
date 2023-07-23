#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int N = 20;
const int S = 9 * 18 + 10;

long long s[N][S];

long long dfs(vector<int> &a, int k, bool limit, int sum)
{
	if (!k)
		return sum;
	if (!limit && s[k][sum] != -1)
		return s[k][sum];

	int up = limit ? a[k] : 9;

	long long res = 0;
	for (int i = 0 ; i <= up ; ++i)
		res = (res + dfs(a, k - 1, limit && i == up, sum + i)) % MOD;

	if (!limit)
		s[k][sum] = res;
	return res;
}

long long f(long long x)
{
	vector<int> a;
	a.push_back(0);

	while (x)
	{
		a.push_back(x % 10);
		x /= 10;
	}

	return dfs(a, a.size() - 1, true, 0);
}

int main()
{
	memset(s, -1, sizeof s);

	int T;
	scanf("%d", &T);

	while (T--)
	{
		long long l, r;
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", (f(r) - f(l - 1) + MOD) % MOD);
	}
	return 0;
}
