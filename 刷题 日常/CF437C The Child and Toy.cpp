#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<int> a; a.resize(n + 1);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int res = 0; while (m--) {
        int l, r; scanf("%d%d", &l, &r);
        res += min(a[l], a[r]);
    } printf("%d\n", res);
    return 0;
}