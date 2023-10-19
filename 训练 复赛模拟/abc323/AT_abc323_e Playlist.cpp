#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

#define rr(x) read<x>()
template<typename _tp>
inline _tp read() {
    _tp num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

ll qpow(ll a, ll b, ll mod) {
    ll res = 1;
    for (; b; b >>= 1, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}

int t[1010];
ll f[20010];

int main() {
    int n = rr(int), x = rr(int);
    int vn = qpow(n, MOD - 2, MOD);
    for (int i = 1; i <= n; ++i) t[i] = rr(int);
    f[0] = 1; for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= n; ++j) if (i >= t[j]) f[i] = (f[i] + f[i - t[j]]) % MOD;
        f[i] = f[i] * vn % MOD;
    } ll res = 0; for (int i = max(0, x - t[1] + 1); i <= x; ++i) {
        res = (res + f[i]) % MOD;
    } res = res * vn % MOD;
    printf("%lld\n", res);
    return 0;
}
