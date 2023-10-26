#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int f[N][N], ans[N];

#define r (l + len - 1)

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string str; cin >> str; int n = (int)str.size();
    // for (int i = 0; i < n; ++i) f[i][i] = 1;
    for (int len = 1; len <= n; ++len) for (int l = 0; l + len - 1 < n; ++l) {
        if (str[l] != str[r] || l + 1 <= r - 1 && f[l + 1][r - 1] == 0) continue;
        ++ans[f[l][r] = f[l][l + (len >> 1) - 1] + 1];
    } for (int i = n - 1; i; --i) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}
