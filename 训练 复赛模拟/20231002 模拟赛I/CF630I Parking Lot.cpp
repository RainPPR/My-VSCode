#include <bits/stdc++.h>
using namespace std;
int n, m; long long mem[70][4][70][2];
long long dfs(int pos, int last, int until, bool flag) {
	if (!pos) return flag || until == n;
	if (~mem[pos][last][until][flag]) return mem[pos][last][until][flag];
	long long res = 0; for (int i = 1; i <= 4; ++i) res += dfs(pos - 1, i, i == last ? until + 1 : 1, flag || (until == n && i != last));
	return mem[pos][last][until][flag] = res;
} int main() {
	memset(mem, -1, sizeof mem);
	cin >> n; m = n + n - 2;
	printf("%lld\n", dfs(m, -1, 0, 0));
	return 0;
}
