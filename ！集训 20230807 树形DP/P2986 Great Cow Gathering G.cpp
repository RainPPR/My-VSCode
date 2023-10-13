#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define _tt(x) template<typename x>
#define gg exit(0)

using pii = pair<int, int>;
using ll = long long;

#define max _max
_tt(tp) inline tp _max(const tp a, const tp b) { return a > b ? a : b; }
#define min _min
_tt(tp) inline tp _min(const tp a, const tp b) { return a < b ? a : b; }
#define abs _abs
_tt(tp) inline tp _abs(const tp a) { return a < 0 ? -a : a; }

const int N = 1e5 + 10;

vector<pii> g[N];

int n, sum;
int s[N];
int sz[N], mc[N], e;

void dfs1(int u, int fa) {
    sz[u] = s[u]; for (pii i : g[u]) if (i.first != fa) {
        int &v = i.first;
        dfs1(v, u); sz[u] += sz[v]; mc[u] = max(mc[u], sz[v]);
    } mc[u] = max(mc[u], sum - sz[u]); if (mc[u] < mc[e]) e = u;
} ll dfs2(int u, int fa, ll d) {
    ll res = d * s[u]; for (pii i : g[u]) if (i.first != fa) {
        res += dfs2(i.first, u, d + i.second);
    } return res;
}

signed main() {
    n = rr; for (int i = 1; i <= n; ++i) s[i] = rr, sum += s[i];
    for (int i = 1; i < n; ++i) {
        int u = rr, v = rr, w = rr;
        g[u].push_back({v, w}), g[v].push_back({u, w});
    } mc[0] = 2e9; dfs1(1, -1);
    printf("%lld\n", dfs2(e, 0, 0));
    return 0;
}