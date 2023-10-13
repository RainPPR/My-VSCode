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

#define tp(t) template<typename t>

#define max _max
tp(t) inline t _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) inline t _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) inline t _abs(const t x) { return x < 0 ? -x : x; }

using pii = pair<int, int>;
using tii = tuple<int, int>;

const int N = 2e5 + 10;

int n;
vector<int> g[N];

void add(int u, int v) { g[u].push_back(v), g[v].push_back(u); }

int lc, rc;
int d[N], f[N];

#define get find_bfs::find
namespace find_bfs {
    pii q[N]; int st, ed;
    int find(int u) {
        d[u] = 0, f[u] = -1; st = 0, ed = 0, q[ed++] = {u, -1};
        int c = u; while (st < ed) {
            pii now = q[st++]; int u = now.first;
            for (int v : g[u]) if (v != now.second) {
                if ((u == lc && v == rc) || (u == rc && v == lc)) continue;
                q[ed++] = {v, u}; f[v] = u;
                if ((d[v] = d[u] + 1) > d[c]) c = v;
        }} return c;
    }
}; namespace find_dfs {
    int c; void dfs(int u, int fa) {
        for (int v : g[u]) if (v != fa) {
            if ((u == lc && v == rc) || (u == rc && v == lc)) continue;
            if ((d[v] = d[u] + 1) > d[c]) c = v; dfs(v, u); f[v] = u;
    }} int find(int u) {
        d[u] = 0, f[u] = -1, c = u;
        dfs(u, -1); return c;
    }
}

int main() {
    int T = rr; while (T--) {
        n = rr; for (int i = 1; i < n; ++i) add(rr, rr);
        lc = rc = -1; int s = get(1), e = get(s);
        lc = e, rc = f[e]; for (int i = 1; i < d[e]; i += 2) tie(lc, rc) = make_tuple(rc, f[rc]);
        int le = get(get(lc)), ls = d[le] + 1; for (int i = d[le]; i > 1; i -= 2) le = f[le];
        int re = get(get(rc)), rs = d[re] + 1; for (int i = d[re]; i > 1; i -= 2) re = f[re];
        printf("%d %d %d\n", max(ls, rs) >> 1, le, re);
        for (int i = 1; i <= n + 1; ++i) g[i].clear();
    }
    return 0;
}
