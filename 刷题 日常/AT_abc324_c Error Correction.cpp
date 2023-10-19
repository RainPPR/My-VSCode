#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string t; cin >> t;
    vector<int> ans;
    for (int T = 1; T <= n; ++T) {
        string s; cin >> s;
        if (t.size() == s.size()) {
            int un = 0; for (int i = 0; i < t.size(); ++i) un += s[i] != t[i];
            if (un <= 1) ans.push_back(T);
        } else if (t.size() - s.size() == 1) {
            bool flag = true;
            for (int i = 0, j = 0; flag && i < s.size(); ++i, ++j) {
                if (s[i] == t[j]) continue;
                --i; if (j - i > 1) flag = false;
            } if (flag) ans.push_back(T);
        } else if (s.size() - t.size() == 1) {
            bool flag = true;
            for (int i = 0, j = 0; flag && i < t.size(); ++i, ++j) {
                if (t[i] == s[j]) continue;
                --i; if (j - i > 1) flag = false;
            } if (flag) ans.push_back(T);
        }
    } cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    return 0;
}
