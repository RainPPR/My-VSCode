#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 10;

#define rr read()
inline int read() {
	int num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

int n, k, a, b;
int root = 1, sl[N << 5], sr[N << 5], idx = 1;

ll c[N << 5], d[N << 5];
void add(int& k, int l, int r, int pos) {
    if (!k) k = ++idx;
    if (l == r) { ++c[k], d[k] = b * c[k]; return; }
    int mid = l + r >> 1, len = r - l + 1;;
    if (mid >= pos) add(sl[k], l, mid, pos);
    else add(sr[k], mid + 1, r, pos);
    c[k] = c[sl[k]] + c[sr[k]];
    d[k] = min(b * c[k] * len, d[sl[k]] + d[sr[k]]);
}

signed main() {
	n = rr, k = rr, a = rr, b = rr;
    d[0] = a; while (k--) add(root, 1, 1 << n, rr);
    printf("%lld", d[1]);
    return 0;
}
