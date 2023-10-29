#include <bits/stdc++.h>

using namespace std;

#define rep(i, x) for (int i = 0; i < (x); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

using ll = long long;
using pii = pair<int, int>;

using vi = vector<int>;
using vp = vector<pii>;

#define sum(x) (x.first + x.second)

int calc(pii a, pii b) {
    if (sum(a) != sum(b)) return sum(a) > sum(b) ? a.first : b.first;
    else return a.second > b.second ? a.first : b.first;
}

signed main() {
    int n = rr, _1, _2; vp a; vi p;
    rep(_, 2 * n) _1 = rr, _2 = rr, a.push_back({_1, _2}), p.push_back(_);
    ll ans = 4e18; do {
        ll res = 0;
        for (int l = 0; l + 1 < p.size(); l += 2) res += calc(a[p[l]], a[p[l + 1]]);
        if (res < ans) ans = res;
    } while (next_permutation(p.begin(), p.end()));
    printf("%lld\n", ans);
    return 0;
}
