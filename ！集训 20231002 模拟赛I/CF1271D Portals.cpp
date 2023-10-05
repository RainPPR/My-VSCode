#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
	int num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

const int N = 5e3 + 10;
const int M = 5e3 + 10;

struct point {
	int a, b, c;
} e[N];

vector<int> g[N];
int from[N];

void add(int v, int u) {
	from[v] = max(from[v], u);
} void build(int n) {
	for (int i = 1; i <= n; ++i) g[from[i]].push_back(i);
}

int f[N][M];

int main() {
	memset(f, ~0x3f, sizeof f);
	int n = rr, m = rr, k = rr;
	for (int i = 1; i <= n; ++i) e[i].a = rr, e[i].b = rr, e[i].c = rr, from[i] = i;
	for (int i = 1; i <= m; ++i) add(rr, rr);
	build(n); f[0][k] = 0;
	for (int i = 1; i <= n; ++i) {
		k += e[i].b;
		for (int j = e[i].a + e[i].b; j <= k; ++j) f[i][j] = f[i - 1][j - e[i].b];
		for (int v : g[i]) for (int j = 0; j < k; ++j) f[i][j] = max(f[i][j], f[i][j + 1] + e[v].c);
	} int res = -1; for (int i = 0; i <= k; ++i) res = max(res, f[n][i]);
	printf("%d\n", res);
	return 0;
}
