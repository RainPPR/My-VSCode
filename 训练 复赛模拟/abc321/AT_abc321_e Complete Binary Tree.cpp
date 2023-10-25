#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr(x) read<x>()
template<typename tp>
inline tp read() {
    tp num = 0; int flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max _max
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

#define getinput(a, b, c) a = rr(ll), b = rr(ll), c = rr(ll)
#define putll(x) printf("%lld\n", x)

ll n, x, k; ll getdown(ll x, ll d) {
    ll l = x, r = x; while (d--) {
        l = l << 1, r = (r << 1) | 1;
        if (l > n) return 0;
    } if (r > n) return n - l + 1;
    return r - l + 1;
} void solve() {
    getinput(n, x, k); ll ans = getdown(x, k);
    while (x > 1 && k >= 2) ans += getdown(x ^ 1, k - 2), x >>= 1, --k;
    (k == 1 && x != 1) ? putll(ans + 1) : putll(ans);
} signed main() {
    int T = rr(int);
    while (T--) solve();
    return 0;
}
