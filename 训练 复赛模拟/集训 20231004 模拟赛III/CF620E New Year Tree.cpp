#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline ll read() {
	ll num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

const int N = 4e5 + 10;

ll w[N];

vector<int> g[N];
void add(int u, int v) {
	g[u].push_back(v), g[v].push_back(u);
}

int sz[N], dfn[N], cnt;
void dfs(int u, int fa) {
	dfn[u] = ++cnt; sz[u] = 1;
	for (int v : g[u]) if (v != fa) dfs(v, u), sz[u] += sz[v];
}

ll a[N], s[N * 3];
ll mark[N * 3];

inline void push(int k) {
	if (!mark[k]) return;
	s[k * 2] = s[k * 2 + 1] = mark[k]; mark[k * 2] = mark[k * 2 + 1] = mark[k]; mark[k] = 0;
} void build(int k, int l, int r) {
	if (l == r) { s[k] = a[l]; return; }
	int mid = l + r >> 1;
	build(k * 2, l, mid), build(k * 2 + 1, mid + 1, r);
	s[k] = s[k * 2] | s[k * 2 + 1];
} void modify(int k, int l, int r, int p, int q, ll c) {
	if (l > q || r < p) return;
	if (l >= p && r <= q) { s[k] = c; mark[k] = c; return; }
	push(k);
	int mid = l + r >> 1; modify(k * 2, l, mid, p, q, c), modify(k * 2 + 1, mid + 1, r, p, q, c);
	s[k] = s[k * 2] | s[k * 2 + 1];
} ll query(int k, int l, int r, int p, int q) {
	if (l > q || r < p) return 0;
	if (l >= p && r <= q) return s[k];
	push(k);
	int mid = l + r >> 1;
	return query(k * 2, l, mid, p, q) | query(k * 2 + 1, mid + 1, r, p, q);
} inline int cbit(ll x) {
	int c = 0; while (x) x -= x & -x, ++c;
	return c;
}

int main() {
	int n = rr, q = rr;
	for (int i = 1; i <= n; ++i) w[i] = 1ll << rr;
	for (int i = 1; i < n; ++i) add(rr, rr);
	dfs(1, 0); for (int i = 1; i <= n; ++i) a[dfn[i]] = w[i];
	build(1, 1, n); while (q--) {
		int op = rr, u = rr;
		if (op == 1) {
			ll c = 1ll << rr;
			modify(1, 1, n, dfn[u], dfn[u] + sz[u] - 1, c);
		} else {
			printf("%d\n", cbit(query(1, 1, n, dfn[u], dfn[u] + sz[u] - 1)));
		}
	} return 0;
}
