#include <bits/stdc++.h>

using std::vector;
using std::tie;
using std::swap;

using pii = std::pair<int, int>;
using vpi = vector<pii>;
using ll = long long;

#define rep(i, x) for (int i = 0; i < (x); ++i)
#define gor(i, x, y) for (int i = x; i < (y); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

const int N = 1e6 + 10;
const int MOD = 998244353;

vector<int> g[N];
void add(int u, int v) {
    g[u].push_back(v), g[v].push_back(u);
}

int p[N], d[N];
void dfs(int u, int fa) {
    for (int v : g[u]) if (v != fa)
    d[v] = d[u] + 1, p[v] = u, dfs(v, u);
}

int f[N], c[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
} void merge(int a, int b) {
    if (d[a] < d[b]) swap(a, b);
    f[a] = b, c[b] += c[a];
}

ll qpow(ll a, ll b, ll m) {
    ll res = 1;
    for (; b; b >>= 1, a = a * a % m) if (b & 1) res = res * a % m;
    return res;
}

signed main() {
    int n = rr; vpi op(n - 1); rep(i, n - 1) op[i] = {rr, rr};
    rep(i, n - 1) add(rr, rr); gor(i, 1, n + 1) f[i] = i, c[i] = 1;
    d[1] = 1; dfs(1, -1); ll res = 1; for (pii k : op) {
        int a, b; tie(a, b) = k; a = find(a), b = find(b);
        if (find(p[a]) != b && find(p[b]) != a) printf("0\n"), exit(0);
        (res *= (1ll * c[a] * c[b]) % MOD) %= MOD; merge(a, b);
    } printf("%lld\n", qpow(res, MOD - 2, MOD));
    return 0;
}
