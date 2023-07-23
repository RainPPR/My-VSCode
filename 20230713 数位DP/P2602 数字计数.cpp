#include <bits/stdc++.h>

using namespace std;

const int N = 15;

long long s[N][N][2];

long long dfs(vector<int> &a, int tar, int pos, int cnt, bool limit, bool lead0)
{
	if (!pos)
		return cnt;

	long long &now = s[pos][cnt][tar != 0];
	if (!limit && !lead0 && ~now)
		return now;

	int up = limit ? a[pos] : 9;

	long long res = 0;
	for (int i = 0 ; i <= up ; ++i)
	{
		int tmp = cnt + (i == tar);
		if (lead0 && tar == 0 && i == 0)
			tmp = 0;
		res += dfs(a, tar, pos - 1, tmp, limit && i == up, lead0 && i == 0);
	}

	if (!limit && !lead0)
		now = res;
	return res;
}

long long ans[N];

void f(long long x, int key)
{
	vector<int> a;
	a.push_back(0);

	while (x)
	{
		a.push_back(x % 10);
		x /= 10;
	}

	for (int i = 0 ; i <= 9 ; ++i)
		ans[i] += key * dfs(a, i, a.size() - 1, 0, true, true);
}

int main()
{
	memset(s, -1, sizeof s);

	long long a, b;
	scanf("%lld %lld", &a, &b);

	f(b, 1);
	f(a - 1, -1);

	for (int i = 0 ; i <= 9 ; ++i)
		printf("%lld ", ans[i]);
	return 0;
}
