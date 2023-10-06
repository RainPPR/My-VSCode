#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline signed read() {
	signed num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

#define rl readline()
inline string readline() {
	string res; char ch = getchar();
	while (ch == '\n' || ch == '\r') ch = getchar();
	while (ch != '\n' && ch != '\r') res.push_back(ch), ch = getchar();
	return res;
}

const int N = 4e5 + 10;
const int INF = 0x3f3f3f3f;

int n, q;
string a[2];

int _min(const int a, const int b) { return a < b ? a : b; }
int _min(const int a, const int b, const int c) { return _min(a, _min(b, c)); }

struct node {
	int d1, d2, d3, d4;
	void debug(char sep = '\n') { fprintf(stderr, "%d %d %d %d%c", d1, d2, d3, d4, sep); }
} s[3 * N]; node operator +(node x, node y) {
	node res = {_min(INF, x.d1 + y.d1, x.d2 + y.d3) + 1, _min(INF, x.d1 + y.d2, x.d2 + y.d4) + 1, _min(INF, x.d4 + y.d3, x.d3 + y.d1) + 1, _min(INF, x.d4 + y.d4, x.d3 + y.d2) + 1};
	return res;
} void build(int k, int l, int r) {
	if (l == r) {
		s[k] = {INF, INF, INF, INF};
		if (a[0][l] == '.') s[k].d1 = 0;
		if (a[1][l] == '.') s[k].d4 = 0;
		if (a[0][l] == '.' && a[1][l] == '.') s[k].d2 = s[k].d3 = 1;
		return;
	} int mid = l + r >> 1;
	build(k * 2, l, mid), build(k * 2 + 1, mid + 1, r);
	s[k] = s[k * 2] + s[k * 2 + 1];
} node query(int k, int l, int r, int p, int q) {
	if (l >= p && r <= q) return s[k];
	int mid = l + r >> 1;
	if (q <= mid) return query(k * 2, l, mid, p, q);
	if (p > mid) return query(k * 2 + 1, mid + 1, r, p, q);
	return query(k * 2, l, mid, p, q) + query(k * 2 + 1, mid + 1, r, p, q);
}

int solve(int l, int r) {
	int x = l > n ? l - n : l;
	int y = r > n ? r - n : r;
	if (x > y) tie(l, r, x, y) = make_tuple(r, l, y, x);
	node now = query(1, 1, n, x, y);
	int res = INF, state = (l > n) + ((r > n) << 1);
	switch(state) {
		case 0: res = now.d1; break;
		case 1: res = now.d3; break;
		case 2: res = now.d2; break;
		case 3: res = now.d4; break;
		default: return -1;
	} return res >= INF ? -1 : res;
}

int main() {
	n = rr, q = rr;
	a[0] = " " + rl, a[1] = " " + rl;
	build(1, 1, n);
	while (q--) printf("%d\n", solve(rr, rr));
	return 0;
}
