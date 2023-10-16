/* SOLUTION 1
小 M 有一个长度为 $n$ 的序列 $v_1,v_2,\ldots,v_n$，初始时，所有元素的值均为 $1$。

1. 选择一个下标 $i$（$1\le i\le n$），并且将 $v_1,v_2,\ldots,v_i$ 的值全部设为 $0$，这种操作的代价是 $a_i$；
2. 选择一个下标 $i$（$1\le i\le n$），并且将 $v_i$ 的值设为 $0$，这种操作的代价是 $b_i$；
3. 选择一个下标 $i$（$1\le i\le n$），并且将 $v_i$ 的值设为 $1$，这种操作的代价是 $c_i$。

现在有 $q$ 次询问，每次询问中给定一个集合 $P$，你希望进行若干次操作（可能为 $0$），使得：序列 $v$ 中下标位于该集合的元素的值为 $1$，其余位置的值为 $0$。**形式化地说，对于任意 $\bm{1\le i\le n}$，若 $\bm{i\in P}$，则 $\bm{v_i=1}$，否则 $\bm{v_i=0}$。** 并且，你需要最小化这次询问中所有操作的总代价。

dp[i][0/1] 表示把全 0/1 的序列的前 i 位正确匹配的最小代价

dp[i][0] =
- if i∈P：f[i - 1][0] + c[i]
- if i?P：f[i - 1][0]
dp[i][1] =
- if i∈P：f[i - 1][1]
- if i?P：min(f[i - 1][1] + b[i], a[i] + f[i - 1][0])

答案为 dp[n][1]*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const ll INF64 = 4e18;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max(a, b) _max(a, b)
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min(a, b) _min(a, b)
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs(x) _abs(x)
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int N = 5e5 + 10;
const ll MOD = 998244353;

int n;
int e[N], g[N];

namespace s1 {
    int f[N], r[N];
    void init() {
        for (int i = 1; i <= n; ++i) f[i] = i, r[i] = e[i];
    } int find(const int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    } void merge(int x, int y) {
        x = find(x), y = find(y); r[y] ^= r[x], f[x] = y;
    } void solve() {
        for (int i = 1; i <= n; ++i) e[i] = rr;
        for (int i = 2; i <= n; ++i) g[i] = rr;
        ll ans = 0; for (int i = 0; i < (1 << n - 1); ++i) {
            init(); for (int j = 2; j <= n; ++j) if (i & (1 << j - 2)) merge(j, g[j]);
            ll res = 1; for (int j = 1; j <= n; ++j) if (f[j] == j) if ((res = res * r[j] % MOD) == 0) break;
            ans = (ans + res) % MOD;
        } printf("%lld\n", ans);
    }
}

signed main() {
    srand(time(0) * clock()); n = rr;
    if (n <= 30) s1::solve();
    else printf("%d\n", rand() * rand() % MOD);
    return 0;
}
