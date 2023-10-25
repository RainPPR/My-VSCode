#include <bits/stdc++.h>

using namespace std;

string s;
int n, k, f[310][310];

#define tp(t) template<typename t> inline t

#define max(a, b) _max(a, b)
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min(a, b) _min(a, b)
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs(x) _abs(x)
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

#define chmin(x, y) x = min(x, y)
#define r l + len - 1

int solve1() {
    for (int i = 0; i < n; ++i) f[i][i] = 1;
    for (int i = 1; i < n; ++i) f[i - 1][i] = s[i - 1] == 'o' && s[i] == 'f' ? 0 : 2;
    for (int len = 3; len <= n; ++len) for (int l = 0; l + len - 1 < n; ++l) {
        f[l][r] = f[l + 1][r] + 1; if (s[l] != 'o') continue;
        for (int i = l + 1; i <= r; ++i) if (s[i] == 'f' && f[l + 1][i - 1] == 0)
            chmin(f[l][r], max(f[i + 1][r] - k, 0));
    } return f[0][n - 1];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> s >> k; n = s.size();
    printf("%d\n", solve1());
    return 0;
}
