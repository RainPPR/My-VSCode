#include <bits/stdc++.h>

using namespace std;

using hp = unsigned long long;

const int N = 5010;

const hp P1 = 53, P2 = 97;
const hp M1 = 1e9 + 7, M2 = 1e9 + 9;

int ans[N];

#define getvar(x) hp l##x = 0, r##x = 0, frac##x = 1

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string str; cin >> str;
    int n = (int)str.size();
    for (int s = 0; s < n; ++s) {
        vector<int> dp(n + 1); getvar(1); getvar(2);
        for (int i = s, j = 0; i < n; ++i, ++j) {
            l1 = (l1 * P1 + str[i]) % M1, r1 = (r1 + str[i] * frac1) % M1, frac1 = frac1 * P1 % M1;
            l2 = (l2 * P2 + str[i]) % M2, r2 = (r2 + str[i] * frac2) % M2, frac2 = frac2 * P2 % M2;
            if (l1 == r1 && l2 == r2) ++ans[dp[j + 1] = dp[j + 1 >> 1] + 1];
        } // for (int i = 1; i <= n; ++i) fprintf(stderr, "%d%c", dp[i], " \n"[i == n]);
    } for (int i = n - 1; i; --i) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}
