#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define rr read()
inline int read() {
    int n = 0, f = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

inline void write(ll x) {
    if (x > 10) write(x / 10);
    putchar(int(x % 10) + '0');
}

int n, m, k;
vector<int> v;

ll res = 0;

inline ll lobit(ll x) {
    return x & -x;
}

inline int popcount(ll r) {
    int i = 0;
    while (r) ++i, r -= lobit(r);
    return i;
}

constexpr double per = CLOCKS_PER_SEC;

void dfs(int now, ll s, ll r) {
    if (now == n) {
        if (popcount(s) <= k) res = (res + r) % MOD;
    } else for (int i = 0; i <= m; ++i)
        dfs(now + 1, s + ((ll)1 << i), r * v[i] % MOD);
}

int main() {
    n = rr, m = rr, k = rr;
    v.resize(m + 1); rep(i, m + 1) v[i] = rr;
    dfs(0, 0, 1); printf("%lld\n", res);
    return 0;
}
