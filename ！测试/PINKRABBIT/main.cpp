#include "optimize.h"
#include <bits/extc++.h>
using namespace std;
using ll = long long;
signed main() {
    constexpr ll N = 999999999, M = (1ll << 24) - 1;
    vector<ll> res; for (ll i = 1, t = 1; i <= N; ++i) {
        if ((i & M) == 0) printf("FINISH %lf%% in %lld (%lld)\n", i * 1.0 / N, (ll)clock(), i);
        t = t * 233333333 % 998244353;
        if (t == 972066295) res.push_back(i);
    } for (auto i : res) printf("PINKRABBIT %lld !!!\n", i);
    printf("CALCULATE %.2e PER SECOND", N * 1000000.0 / clock() / CLOCKS_PER_SEC);
    getchar(); return 0;
}
