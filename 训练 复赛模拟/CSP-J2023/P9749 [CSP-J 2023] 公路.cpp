#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

const int N = 1e5 + 10;

int v[N], a[N];

signed main() {
    int n, d; scanf("%d%d", &n, &d);
    rep(i, n - 1) scanf("%d", v + i);
    rep(i, n) scanf("%d", a + i);
    ll oil = 0, dis = 0, w = 1e9, res = 0;
    rep(i, n) {
        ll nd = dis - d * oil;
        if (nd > 0) nd = (nd + d - 1) / d, oil += nd, res += 1ll * nd * w;
        w = min(w, (ll)a[i]), dis += v[i];
    } printf("%lld\n", res);
    return 0;
}
