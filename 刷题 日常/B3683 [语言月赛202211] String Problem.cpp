#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

using memory = unordered_set<int>;

#define write(neq) cout << (cnt == 0 ? "Yes\n" : "No\n");

const int N = 1e6 + 10;

int neq[N], cnt;

void solve() {
    int n, q; string s, t; cin >> n >> q >> s >> t;
    fill(neq, neq + n, 0); cnt = 0;
    rep(i, n) if (s[i] not_eq t[i]) neq[i] = 1, ++cnt;
    write(neq); while (q--) {
        int o, p; string c; cin >> o >> p >> c;
        (o == 0 ? s : t)[--p] = c[0];
        if (s[p] == t[p] && neq[p]) neq[p] = 0, --cnt;
        else if (s[p] != t[p] && !neq[p]) neq[p] = 1, ++cnt;
        write(neq);
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T; while (T--) solve();
    return 0;
}
