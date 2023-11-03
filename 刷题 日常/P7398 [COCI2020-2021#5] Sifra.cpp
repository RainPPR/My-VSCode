#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

signed main() {
    string str; cin >> str;
    unordered_set<string> cnt;
    rep(i, str.size()) {
        if (!isdigit(str[i])) continue;
        string num;
        while (isdigit(str[i])) num += str[i], ++i;
        cnt.insert(num);
    } printf("%d\n", (int)cnt.size());
    return 0;
}
