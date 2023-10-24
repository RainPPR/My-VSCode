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

const int N = 1e5 + 10;

int a[N];

signed main() {
    // freopen("in.txt", "r", stdin);
    int T = rr; while (T--) {
        int n = rr, k = rr;
        for (int i = 1; i <= n; ++i) a[i] = rr;
        int res = 1e9; if (k == 4) {
            int cnt = 0; for (int i = 1; i <= n; ++i) cnt += a[i] % 2 == 0;
            if (cnt == 0) res = 2;
            else if (cnt == 1) res = 1;
            else res = 0;
        } for (int i = 1; i <= n; ++i) {
            int ad = (a[i] + k - 1) / k * k - a[i];
            res = min(res, ad);
        } printf("%d\n", res);
    } return 0;
}
