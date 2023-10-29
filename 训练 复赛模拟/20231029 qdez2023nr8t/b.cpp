#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define rep(i, x) for (int i = 0; i < (x); ++i)

using ll = long long;
using vi = vector<int>;

const ll MOD = 998244353;

int n; vi a;

set<pair<int, vi>> mem;

ll cnt = 0; void dfs(int k, vi now) {
    if (mem.count({k, now})) return;
    mem.insert({k, now});
    if (k == n) { cnt = (cnt + 1) % MOD; return; }
    dfs(k + 1, now); now.push_back(a[k]);
    dfs(k + 1, now);
}

signed main() {
    n = rr; rep(i, n) a.push_back(rr);
    dfs(0, vi()); printf("%lld\n", cnt);
    return 0;
}
