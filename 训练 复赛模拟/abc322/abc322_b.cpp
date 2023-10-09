#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; string s, t;
    cin >> n >> m >> s >> t;
    bool pref = true, suff = true;
    for (int i = 0; i < n; ++i) if (s[i] != t[i]) { pref = false; break; }
    for (int i = n - 1, j = m - 1; ~i; --i, --j) if (s[i] != t[j]) { suff = false; break; }
    if (pref && suff) printf("0\n");
    else if (pref) printf("1\n");
    else if (suff) printf("2\n");
    else printf("3\n");
    return 0;
}
