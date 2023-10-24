#include <bits/stdc++.h>

#define int long long

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
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

signed main() {
    // freopen("in.txt", "r", stdin);
    int T = rr; while (T--) {
        int n = rr, lt = rr, res = 0, mem = 0;
        for (int i = 2; i <= n; ++i) {
            int a = rr, ad = max((int)ceil(log2(1.0 * lt / a) + mem), 0ll);
            // cerr << lt << " " << a << ": " << ad << " " << mem << endl;
            res += ad, lt = a, mem = ad;
        } printf("%lld\n", res);
    } return 0;
}
