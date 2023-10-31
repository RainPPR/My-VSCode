#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 998244353;

#define rr read()
inline int read() {
    int num = 0, flag = 0, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) flag |= ch == '-';
    for (; isdigit(ch); ch = getchar()) num = (num << 1) + (num << 3) + ch - '0';
    return flag ? -num : num;
}

inline ll qpow(ll a, int b, ll p) {
    ll r = 1;
    for (; b; b >>= 1, a = a * a % p) if (b & 1) r = r * a % p;
    return r;
}

signed main() {
    int n = rr, inv = qpow(n, MOD - 2, MOD);
    ll r = 0, p = inv; while (n--)
        r = (r + rr * p) % MOD, p = (p + p * inv) % MOD;
    printf("%lld\n", r);
    return 0;
}
