#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

const int N = 110;
const int K = 1010;

const ll INF = 0x3f3f3f3f3f3f3f3f;

int d[N];
ll f[N][K];

#define tomin(x, y) x = min(x, y)

signed main() {
    int n = rr; for (int i = 1; i <= n; ++i) d[i] = rr;
    int l1 = rr, c1 = rr, k1 = rr;
    int l2 = rr, c2 = rr, k2 = rr;
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= k1; ++j) {
        f[i][j] = INF; for (int k = 0; k <= j; ++k) tomin(f[i][j], f[i - 1][j - k] + (max(d[i] - 1ll * k * l1, 0ll) + l2 - 1) / l2);
    } ll res = INF; for (int i = 0; i <= k1; ++i) {
        if (f[n][i] <= k2) res = min(res, 1ll * c1 * i + 1ll * c2 * f[n][i]);
    } printf("%lld\n", res == INF ? -1 : res);
    return 0;
}
