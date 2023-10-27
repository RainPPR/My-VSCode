#include <bits/stdc++.h>

using std::cin;
using std::string;

using ll = long long;
const ll MOD = 998244353;

const int to[256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     52, 53, 54, 55, 56, 57, 58, 59, 60, 61,   0, 0,
                     0,  0,  0,  0,  0,  26, 27, 28, 29, 30, 31, 32,
                     33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
                     45, 46, 47, 48, 49, 50, 51, 0,  0,  0, 0, 0, 0,
                     0, 1, 2, 3,  4, 5, 6, 7, 8,  9, 10, 11, 12, 13,
                     14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

ll f[2][65][2][2][2], g[2][2][2];

#define rep(i, x) for (int i = 0; i < (x); ++i)
#define gor(i, l, r) for (int i = (l); i < (r); ++i)

#define _r_ab rep(a, 2) rep(b, 2)
#define _r_ac rep(a, 2) rep(c, 2)
#define _r_bc rep(b, 2) rep(c, 2)
#define _r_abc rep(a, 2) rep(b, 2) rep(c, 2)

#define ths to[sp]
#define ff f[pos][now]
#define f0 f[pos ^ 1][now]

#define add(x, a) (x += (a) % MOD) %= MOD
#define sub(x, a) (x = x - (a) % MOD + MOD) %= MOD
#define as2(x, a, b) add(x, a), sub(x, b)

#define _ab(x) x[a][b][0] + x[a][b][1]
#define _ac(x) x[a][0][c] + x[a][1][c]
#define _bc(x) x[0][b][c] + x[1][b][c]
#define _abc(x) x[a][b][c]

#define lw(x) islower(x)
#define up(x) isupper(x)
#define dg(x) isdigit(x)

inline void do_lw(int pos, int now) {
    _r_bc as2(ff[1][b][c], _bc(g), _bc(f0));
} inline void do_up(int pos, int now) {
    _r_ac as2(ff[a][1][c], _ac(g), _ac(f0));
} inline void do_dg(int pos, int now) {
    _r_ab as2(ff[a][b][1], _ab(g), _ab(f0));
}

inline void init(int s0) {
    if (lw(s0)) f[0][to[s0]][1][0][0] = 1, f[0][to[s0] + 26][0][1][0] = 1;
    else if (up(s0)) f[0][to[s0]][0][1][0] = 1;
    else if (dg(s0)) f[0][to[s0]][0][0][1] = 1;
    else {
        rep(i, 26) f[0][to[i + 'a']][1][0][0] = 1;
        rep(i, 26) f[0][to[i + 'A']][0][1][0] = 1;
        rep(i, 10) f[0][to[i + '0']][0][0][1] = 1;
    }
}

inline void calc(int pos, int sp) {
    _r_abc { _abc(g) = 0; rep(now, 62) _abc(ff) = 0, add(_abc(g), _abc(f0)); }
    if (lw(sp)) do_lw(pos, ths), do_up(pos, ths + 26);
    else if (up(sp)) do_up(pos, ths);
    else if (dg(sp)) do_dg(pos, ths);
    else {
        gor(now,  0, 26) do_lw(pos, now);
        gor(now, 26, 52) do_up(pos, now);
        gor(now, 52, 62) do_dg(pos, now);
    }
}

ll solve(int n, string str) {
    init(str[0]); int j = 1;
    for (int pos = 1; pos < n; ++pos, j ^= 1) calc(j, str[pos]); 
    ll res = 0; rep(i, 62) (res += f[j ^ 1][i][1][1][1]) %= MOD;
    return res;
}

signed main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; string str; cin >> n >> str;
    printf("%lld\n", solve(n, str));
    return 0;
}
