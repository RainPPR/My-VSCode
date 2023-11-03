#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

string s; int n;

int ra, ro;

vector<int> lta, lto;

int dfs(int l, int r) {
    if (lta[r] < l and lto[r] < l) {
        if (s[l] == '(' and s[r - 1] == ')')
            return dfs(l + 1, r - 1);
        return s[l] - '0';
    } else if (lto[r] > l) {
        int a = dfs(l, lto[r]);
        if (a == 1) return (++ro, 1);
        return a or dfs(lto[r] + 1, r);
    } else {
        int a = dfs(l, lta[r]);
        if (a == 0) return (++ra, 0);
        return a and dfs(lta[r] + 1, r);
    }
}

signed main() {
    cin >> s; n = s.size();
    vector<int> laya(n + 1), layo(n + 1);
    lta.resize(n + 1), lto.resize(n + 1);
    laya[0] = layo[0] = -1;
    for (int i = 0, in = 0; i < n; ++i) {
        if (s[i] == '(') ++in;
        if (s[i] == ')') --in;
        if (s[i] == '&') laya[in] = i;
        if (s[i] == '|') layo[in] = i;
        lta[i + 1] = laya[in];
        lto[i + 1] = layo[in];
    } int res = dfs(0, n);
    printf("%d\n%d %d\n", res, ra, ro);
    return 0;
}
