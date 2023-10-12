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

#define max _max
_tt(tp) inline tp _max(const tp a, const tp b) { return a > b ? a : b; }
#define min _min
_tt(tp) inline tp _min(const tp a, const tp b) { return a < b ? a : b; }
#define abs _abs
_tt(tp) inline tp _abs(const tp a) { return a < 0 ? -a : a; }

const int N = 1e5 + 10;

vector<pii> g[N];
inline void add(const int u, const int v) { g[u].push_back({v, 1}), g[v].push_back({u, 1}); }

int ans; int dfs1(int u, int fa) {
    int m1 = 0, m2 = 0;
    for (pii i : g[u]) if (i.first != fa) {
        int d = dfs1(i.first, u) + i.second;
        if (d > m1) m2 = m1, m1 = d;
        else if (d > m2) m2 = d;
    } ans = max(ans, m1 + m2); 
    return m1;
}

int c, d[N], f[N]; void dfs2(int u, int fa) {
    for (pii i : g[u]) if (i.first != fa) {
        if ((d[i.first] = d[u] + 1) > d[c]) c = i.first;
        f[i.first] = u; dfs2(i.first, u);
    }
}

int main() {
    int n = rr, k = rr;
    for (int i = 1; i < n; ++i) add(rr, rr);
    if (k == 1) {
        dfs1(1, -1); printf("%d\n", n + n - ans - 1);
    } else {
        c = 1, d[c] = 0; dfs2(1, -1);
        d[c] = 0, f[c] = -1; dfs2(c, -1);
        int res = d[c]; set<pii> sub;
        for (int l = c, r = f[c]; ~r; l = r, r = f[r]) sub.emplace(l, r);
        for (int u = 1; u <= n; ++u) for (pii &i : g[u])
            if (sub.count({u, i.first}) || sub.count({i.first, u})) i.second = -1;
        dfs1(1, -1); printf("%d\n", n + n - res - ans);
    }
    return 0;
}