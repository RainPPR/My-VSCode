#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using i2 = __int128;

const int INF = 0x3f3f3f3f;
const ll INF64 = (ll)INF * INF;
const i2 INF128 = (i2)INF64 * INF64;

#define rr read()
inline ll read() {
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline

#define max _max
tp(t) t _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) t _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) t _abs(const t x) { return x < 0 ? -x : x; }

tp(t) void write(const t x, bool sep = 1) {
    if (x > 9) write(x / 10, 0);
    putchar(x % 10 + '0');
    if (sep) putchar('\n');
}

#define open(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
#define close() fclose(stdin), fclose(stdout);

const int M = 1e5 + 10;
const int N = 1e7 + 10;
const int Q = 1e5 + 10;

const i2 MOD = i2(1) << 64;

struct obj {
    ll a, b;
} o[M];

ll e[Q];
i2 f[N];

void solve() {
    int m = rr, q = rr; ll xn = 0;
    int idx = 0; while (m--) {
        ++idx, o[idx].a = rr, o[idx].b = rr;
        if (idx > 1 && (1.0 * o[idx].b / o[idx].a) >= (1.0 * o[idx - 1].b / o[idx - 1].a)) --idx;
    } m = idx;
    for (int i = 1; i <= q; ++i) e[i] = rr, xn = max(xn, e[i] - 1);
    f[0] = 0; for (int i = 1; i <= xn; ++i) f[i] = INF128;
    for (int i = 1; i <= m; ++i) for (ll j = o[i].a; j <= xn; ++j) {
        f[j] = min(f[j], f[j - o[i].a] + o[i].b);
    } for (int i = 1; i <= xn; ++i) f[i] = (f[i] % MOD + f[i - 1]) % MOD;
    for (int i = 1; i <= q; ++i) write(e[i] == 0 ? 0 : f[e[i] - 1] % MOD);
}

int main() {
    // open(paradise);
    int T = rr, op = rr;
    while (T--) {
        solve();
    } return 0;
}
