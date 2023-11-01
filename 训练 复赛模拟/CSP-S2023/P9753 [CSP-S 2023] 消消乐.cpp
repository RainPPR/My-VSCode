#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

const int N = 2e6 + 10;

using ll = long long;
using tp = unsigned long long;

#define tail1(a) a[a.size() - 1]
#define tail2(a) a[a.size() - 2]

const tp MOD = 998244353;
const tp BASE = 53;

tp FRAC[N];

signed main() {
    //ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; string s; cin >> n >> s;
    FRAC[0] = 1; rep(i, n) FRAC[i + 1] = FRAC[i] * BASE % MOD;
    string sub; tp h = 0;
    unordered_map<tp, int> cnt = {{0, 1}};
    ll ans = 0; for (char c : s) {
        sub.push_back(c); h = (h + c * FRAC[sub.size() - 1] % MOD) % MOD;
        while (sub.size() >= 2 && tail1(sub) == tail2(sub)) {
            h = (h - tail1(sub) * FRAC[sub.size() - 1] % MOD + MOD) % MOD;
            sub.pop_back();
            h = (h - tail1(sub) * FRAC[sub.size() - 1] % MOD + MOD) % MOD;
            sub.pop_back();
        } ans += cnt[h], ++cnt[h];
    } cout << ans << endl;
    return 0;
}
