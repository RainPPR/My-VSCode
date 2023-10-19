#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const ll INF64 = 4e18;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max(a, b) _max(a, b)
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min(a, b) _min(a, b)
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs(x) _abs(x)
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int M = 1e6 + 10;
const int N = 1e6 + 10;

int n, m, k;
int s[M], pre[N];

int get(int a) {
    int l = -1, r = 0, res = 0;
    while (r < n) {
        if (pre[r] <= l) return INF;
        l = pre[r], r = pre[r] + a; ++res;
    } return res;
}

signed main() {
    n = rr, m = rr, k = rr;
    for (int i = 1; i <= m; ++i) s[rr] = 1;
    if (s[0]) printf("-1\n"), exit(0);
    int now = 0; for (int i = 0; i <= n; ++i) {
        if (!s[i]) pre[i] = now = i;
        else pre[i] = now;
    } ll res = INF64; for (int c = 1; c <= k; ++c) {
        int t = get(c), e = rr;
        if (t != INF) res = min(res, 1ll * e * t);
    } printf("%lld\n", res == INF64 ? -1ll : res);
    return 0;
}
