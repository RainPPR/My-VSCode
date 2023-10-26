// CF1728D Letter Picking

#include <bits/stdc++.h>

using namespace std;

#define gor(i, n) for (int i = 0; i < (n); ++i)

#define tp(t) template<typename t> inline t
#define max _max
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int N = 2e3 + 10;
const int INF = 1e9;

int f[N][N];
const string res[3] = {"Alice", "Draw", "Bob"};

int comp(const char a, const char b) {
    if (a > b) return 0;
    else if (a < b) return 2;
    else return 1;
}

#define r l + len - 1

void solve(const string s) {
    int n = s.size(); gor(i, n - 1) f[i][i + 1] = s[i] == s[i + 1];
    for (int len = 4; len <= n; len += 2) gor(l, n - len + 1) {
        int f1 = f[l + 2][r] == 1 ? comp(s[l], s[l + 1]) : f[l + 2][r];
        int f2 = f[l + 1][r - 1] == 1 ? comp(s[l], s[r]) : f[l + 1][r - 1];
        int f3 = f[l][r - 2] == 1 ? comp(s[r], s[r - 1]) : f[l][r - 2];
        int f4 = f[l + 1][r - 1] == 1 ? comp(s[r], s[l]) : f[l + 1][r - 1];
        f[l][r] = min(max(f1, f2), max(f3, f4));
    } cout << res[f[0][n - 1]] << endl;
}

#undef r

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; string str; cin >> t;
    while (t--) cin >> str, solve(str);
    return 0;
}
