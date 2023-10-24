#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        memset(cnt, 0, sizeof cnt);
        for (int ch : s) ++cnt[ch - 'a'];
        int res = 0; for (int i = 0; i < 26; ++i) res += cnt[i] & 1;
        printf(res - 1 <= k ? "YES\n" : "NO\n");
    } return 0;
}