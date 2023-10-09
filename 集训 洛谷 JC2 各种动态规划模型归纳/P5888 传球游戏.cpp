#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MOD = 998244353;
const int N = 5e4 + 10, M = 200, K = 5e4 + 10;

int n, m, k;
int s[N];
int f[M][N];
unordered_map<int, int> un_ok[N];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	int a, b;
	for (int i = 1 ; i <= k ; ++i)
	{
		scanf("%d %d", &a, &b);
		un_ok[a][b] = 1;
	}
	
	for (int i = 1 ; i <= n ; ++i)
		un_ok[i][i] = 1;
	f[0][1] = s[0] = 1;
	
	for (int i = 1 ; i <= m ; ++i)
	{
		for (int j = 1 ; j <= n ; ++j)
		{
			f[i][j] = s[i - 1];
			for (pair<int, int> t : un_ok[j])
				(f[i][j] += MOD - f[i - 1][t.first]) %= MOD;
			(s[i] += f[i][j]) %= MOD;
		}
	}
	
	printf("%d", f[m][1]);
	return 0;
}
