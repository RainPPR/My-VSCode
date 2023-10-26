// CF985F Isomorphic Strings

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define fastio() std::ios::sync_with_stdio(false); cin.tie(nullptr);
#define gor(i, n) for (int i = 0; i < (n); ++i)
#define get3(a, b, c) int a, b, c; cin >> a >> b >> c;
#define YN(x) cout << (x ? "YES\n" : "NO\n") << endl;

const int N = 2e5 + 10;

int n, h[26][N];

using tp = unsigned long long;
using vtp = vector<tp>;

const tp p1 = 53, p2 = 97;
const tp m1 = 1e9 + 7, m2 = 1e9 + 9;

tp f1[N], f2[N];
tp h1[26][N], h2[26][N];

#define _do_f(x, i) f##x[i] = f##x[i - 1] * p##x % m##x
#define _do_h(x, i, j) h##x[i][j] = (h##x[i][j - 1] * p##x + h[i][j]) % m##x
#define _get_h(x, i, l, r) (h##x[i][r] - h##x[i][l - 1] * f##x[r - l + 1] % m##x + m##x) % m##x
#define _pb_l(x) _1.push_back(_get_h(x, i, l, l + s - 1))
#define _pb_r(x) _2.push_back(_get_h(x, i, r, r + s - 1))
#define _ck_s(x) sort(_##x.begin(), _##x.end())

bool check(int x, int l, int r, int s, vtp _1 = vtp(), vtp _2 = vtp()) {
    if (x == 1) for (int i = 0; i < 26; ++i) _pb_l(1), _pb_r(1);
    else for (int i = 0; i < 26; ++i) _pb_l(2), _pb_r(2);
    _ck_s(1), _ck_s(2); return _1 == _2;
}

signed main() {
    fastio(); int q; string str; cin >> n >> q >> str;
    f1[0] = f2[0] = 1; for (int i = 1; i <= n; ++i) _do_f(1, i), _do_f(2, i);
    gor(i, n) h[str[i] - 'a'][i + 1] = 1;
    gor(i, 26) for (int j = 1; j <= n; ++j) _do_h(1, i, j), _do_h(2, i, j);
    while (q--) { get3(l, r, s); YN(check(1, l, r, s) && check(2, l, r, s)); }
    return 0;
}
