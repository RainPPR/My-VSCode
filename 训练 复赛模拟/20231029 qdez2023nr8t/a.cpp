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

void solve(ll n, ll k) {
    ll res = 0; while (k--)  {
        auto t = n; --n, ++res;
        ll kk = 1;
        while ((t & 1) == 0) ++res, t >>= 1, ++kk;
        cerr << n + 1 << " - " << n << ": " << kk << endl;
    } printf("%lld\n", res);
}

signed main() {
    int T = rr; while (T--) {
        ll n = rr, k = rr; solve(n, k);
    } return 0;
}
