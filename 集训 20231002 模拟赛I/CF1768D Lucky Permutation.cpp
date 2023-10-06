#include <bits/stdc++.h>

using namespace std;

#define ur uread()
inline unsigned uread() {
	unsigned num = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
	return num;
}

const int N = 2e5 + 10;

int a[N];

int f[N], rc = 0;
int sz[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
} void add(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) f[a] = b, sz[b] += sz[a], --rc;
}

signed main() {
	int T = ur; while (T--) {
		int n = ur; int flag = 1;
		rc = n; for (int i = 1; i <= n; ++i) {
			f[i] = i, sz[i] = 1;
		} for (int i = 1; i <= n; ++i) {
			a[i] = ur; if (i != a[i]) add(i, a[i]);
		} int res = 0; for (int i = 1; i <= n; ++i) {
			if (f[i] == i) res += sz[i] - 1;
		} for (int i = 1; i <= n; ++i) {
			int j = find(i); if (find(i + 1) == j || find(i - 1) == j) { flag = -1; break; }
		} printf("%d\n", res + flag);
	} return 0;
}
