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

const int N = 2e5 + 10;
const int M = N << 1;

struct node {
	ll l, r;
} a[N];

unordered_map<ll, ll> to; // 原->新
unordered_map<ll, ll> rto; // 新->原
unordered_map<ll, ll> d; // 原来的点的点权

ll s[M]; // 差分数组
ll z[N]; // 答案

int main() {
	int n = rr;
	vector<ll> pt; for (int i = 0; i < n; ++i) {
		ll l = rr, r = rr;
		a[i].l = l, a[i].r = r, d[l] = d[r] = 1;
		pt.push_back(l), pt.push_back(r);
		if (r - l > 1) pt.push_back(l + 1), d[l + 1] = r - l - 1;
	} sort(pt.begin(), pt.end()); int m = unique(pt.begin(), pt.end()) - pt.begin();
	for (int i = 0; i < m; ++i) {
		to[pt[i]] = i, rto[i] = pt[i];
	} for (int i = 0; i < n; ++i) {
		++s[to[a[i].l]], --s[to[a[i].r] + 1];
	} z[s[0]] = d[rto[0]]; for (int i = 1; i < m; ++i) {
		s[i] = s[i] + s[i - 1]; z[s[i]] += d[rto[i]];
	} for (int i = 1; i <= n; ++i) {
		printf("%lld ", z[i]);
	} return 0;
}
