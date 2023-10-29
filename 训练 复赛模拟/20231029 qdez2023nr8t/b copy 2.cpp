#include <bits/stdc++.h>

using std::vector;
using std::map;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

using ll = long long;
using vi = vector<int>;

const int N = 1e6 + 10;
const ll MOD = 998244353;

map<int, int> appear;
int isfirst[N], tolast[N];

ll f[N], s[N];

signed main() {
    int n = rr; for (int i = 1; i <= n; ++i) {
        int a = rr; appear.count(a) ? tolast[i] = appear[a] : tolast[i] = isfirst[i] = 1;
        appear[a] = i;
    } f[1] = s[1] = 1; for (int i = 2; i <= n; ++i) {
        f[i] = (s[i - 1] - s[tolast[i] - 1] + isfirst[i] + MOD) % MOD;
        s[i] = (s[i - 1] + f[i]) % MOD;
    } printf("%lld\n", (s[n] + 1) % MOD);
    return 0;
}
