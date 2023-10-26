// rp++ Chtholly bless me
// AT_abc322_e Product Development

#include <bits/stdc++.h>

using std::vector;
using std::map;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

using _v = vector<int>;
using _m = map<vector<int>, long long>;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define gor(i, n) for (int i = 0; i < (n); ++i)
#define chmin(a, x) a = min(a, x)
#define r _v(k, p)

signed main() {
    int n = rr, k = rr, p = rr;
    _m dp; dp[_v(k)] = 0; gor (i, n) {
        int c = rr; _v a; gor (j, k) a.push_back(rr);
        auto bak = dp; for (auto _ : bak) {
            auto t = _.first; auto nw = _.second + c;
            gor (j, k) t[j] = min(t[j] + a[j], p);
            dp.count(t) ? chmin(dp[t], nw) : dp[t] = nw;
    }} dp.count(r) ? printf("%lld\n", dp[r]) : printf("-1\n");
    return 0;
}
