#include <bits/stdc++.h>

using namespace std;

map<int, int> gift;

signed main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x); ++gift[x];
    } int sum = 0; for (auto &i : gift) {
        i.second = (sum += i.second);
    } int lt = 0, ans = 0; for (auto i : gift) {
        auto t = gift.lower_bound(i.first + m); --t;
        lt = i.second; ans = max(ans, t->second - lt);
    } printf("%d\n", ans);
    return 0;
}
