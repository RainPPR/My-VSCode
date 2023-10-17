#include <bits/stdc++.h>
using namespace std;
inline bool cmp(const string a, const string b) { return a + b < b + a; }
signed main() {
    vector<string> str; str.clear();
    int n; cin >> n;
    string tmp; for (int i = 1; i <= n; ++i) cin >> tmp, str.push_back(tmp);
    sort(str.begin(), str.end(), cmp);
    string res; for (string i : str) res += i;
    cout << res << endl;
    return 0;
}
