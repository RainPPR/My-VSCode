#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 10;

int n;
int a[N];
int s[N];

unordered_map<int, int> f[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= n ; ++j)
			if (i == j)
				f[i][i] = 0;
			else
				f[i][j] = 0x3f3f3f3f;

	for (int i = n - 1 ; i >= 1 ; --i)
		for (int j = i + 1 ; j <= n ; ++j)
			for (int k = i ; k < j ; ++k)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);

	printf("%d\n", f[1][n]);
	return 0;
}
