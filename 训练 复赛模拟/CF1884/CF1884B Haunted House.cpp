#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int n, string s) {
    ll ans = 0;
    for (int i = n - 1, j = n - 1; ~i; --i, --j) {
        while (j >= 0 && s[j] == '1') --j;
        if (j < 0) printf("-1 ");
        else printf("%lld ", ans += i - j);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; string s;
        cin >> n >> s;
        solve(n, s);
    } return 0;
}
