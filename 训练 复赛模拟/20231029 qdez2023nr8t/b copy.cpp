#include <bits/stdc++.h>

using namespace std;

#define rep(i, x) for (int i = 0; i < (x); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

using ll = long long;
using vi = vector<int>;

const ll MOD = 998244353;

int n; set<vi> res;

signed main() {
    n = rr; res.emplace(vi());
    rep(i, n) {
        int x = rr; auto bak = res;
        for (auto t : bak) t.push_back(x), res.emplace(t);
    } printf("%lld\n", ll(res.size()) % MOD);
    return 0;
}
