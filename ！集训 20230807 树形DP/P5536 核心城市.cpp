#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

#define max _max
#define min _min
template<typename _Tp> inline _Tp _max(const _Tp a, const _Tp b) { return a > b ? a : b; }
template<typename _Tp> inline _Tp _min(const _Tp a, const _Tp b) { return a < b ? a : b; }

using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, k;
vector<int> g[N];

inline void add(int u, int v) { g[u].push_back(v), g[v].push_back(u); }

int c, a[N];
int d[N], f[N];
void dfs(int u, int fa) {
    for (int v : g[u]) if (v != fa) {
        d[v] = d[u] + 1, f[v] = u; dfs(v, u);
        if (d[v] > d[c]) c = v;
    }
} void dfk(int u, int fa) {
    for (int v : g[u]) if (v != fa)
        dfk(v, u), a[u] = max(a[u], a[v] + 1);
} int solve() {
    c = 1, d[1] = 1; dfs(1, -1);
    d[c] = 1; dfs(c, -1);
    int lc = d[c] >> 1; for (int i = 1; i <= lc; ++i) c = f[c];
    dfk(c, -1); sort(a + 1, a + 1 + n, greater<int>());
    return a[k + 1] + 1;
}

int main() {
    n = rr, k = rr;
    for (int i = 1; i < n; ++i) add(rr, rr);
    printf("%d\n", solve());
    return 0;
}
