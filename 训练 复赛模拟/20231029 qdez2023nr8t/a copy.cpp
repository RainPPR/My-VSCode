#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline ll read() {
    ll num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

ll solve(ll x) {
    ll res = 0;
    while (x) res += x, x >>= 1;
    return res;
}

signed main() {
    int T = rr; while (T--) {
        ll n = rr, k = rr;
        if (n == k) printf("%lld\n", solve(n));
        else printf("%lld\n", solve(n) - solve(n - k));
    } return 0;
}
