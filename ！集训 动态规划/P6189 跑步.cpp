#include <bits/stdc++.h>

#define ur uread()

using namespace std;

typedef long long ll;

unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

const int N = 1e5 + 10;
const int M = 320;

ll f[N], g[M][N];

// f[i][j] = f[i - 1][j] + f[i][j - i]
// g[i][j] = g[i][j - i] + g[i - 1][j - m - 1]

ll solve(const int n, const int m, const int p) {
    ll ans = 0; f[0] = g[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) f[j] = (f[j] + f[j - i]) % p;
    } for (int i = 1; i <= m; ++i) {
        int j = i; for (; j < m; ++j) g[i][j] = g[i][j - i];
        for (; j <= n; ++j) g[i][j] = (g[i][j - i] + g[i - 1][j - m - 1]) % p;
    } for (int i = 0; i <= n; ++i) {
        ll sum = 0; for (int j = 0; j <= m; ++j) sum = (sum + g[j][n - i]) % p;
        ans = (ans + f[i] * sum) % p;
    } return ans;
}

signed main() {
    const int n = ur, p = ur; printf("%lld\n", solve(n, sqrt(n), p));
    return 0;
}
