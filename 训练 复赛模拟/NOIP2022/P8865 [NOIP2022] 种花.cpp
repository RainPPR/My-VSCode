#include <bits/stdc++.h>

using namespace std;

#define ttp template<typename tp>

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

using ll = long long;

const int N = 1010;
const ll MOD = 998244353;

int n, m, qc, qf;
string a[N];

template<int m>
class modint {
private:
    ll value;
public:
    modint() { value = 0; }
    modint(int x) { value = x % m; }
    modint(ll x) { value = x % m; }
    ll get() { return value; }
    void print(char sep = '\n') { printf("%lld%c", value, sep); }
    ttp modint operator +(const tp v) { return modint((value + v) % m); }
    ttp modint operator +=(const tp v) { value = (value + v) % m; return *this; }
};

void input() {
    cin >> n >> m >> qc >> qf;
    rep(i, n) cin >> a[i];
}

namespace calc {
    int frt[N][N];
    ll upto[N][N], sumc[N][N];
    ll upon[N][N], sumf[N][N];
    pair<ll, ll> solve() {
        modint<MOD> res1, res2;
        rep(i, n) frt[i][m] = -1;
        rep(i, n) for (int j = m - 1; ~j; --j) frt[i][j] = a[i][j] not_eq '1' ? frt[i][j + 1] + 1 : -1;
        rep(j, m) upto[0][j] = a[0][j] not_eq '1' ? frt[0][j] : 0;
        gor(i, 1, n) rep(j, m) upto[i][j] = a[i][j] not_eq '1' ? (upto[i - 1][j] + frt[i][j]) % MOD : 0;
        gor(i, 2, n) rep(j, m) sumc[i][j] = a[i][j] not_eq '1' and a[i - 1][j] not_eq '1' ? frt[i][j] * upto[i - 2][j] % MOD : 0, res1 += sumc[i][j];
        gor(i, 2, n) rep(j, m) upon[i][j] = a[i][j] not_eq '1' ? (upon[i - 1][j] + sumc[i][j]) % MOD : 0;
        gor(i, 3, n) rep(j, m) if (a[i][j] not_eq '1') res2 += upon[i - 1][j];
        return {res1.get() * qc, res2.get() * qf};
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, id; cin >> T >> id;
    while (T--) {
        input(); auto r = calc::solve();
        printf("%lld %lld\n", r.first, r.second);
    } return 0;
}
