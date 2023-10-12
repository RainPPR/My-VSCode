#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

const int N = 1e5 + 10;

#define max _max
inline int _max(const int a, const int b) { return a > b ? a : b; }
#define min _min
inline int _min(const int a, const int b) { return a < b ? a : b; }

vector<int> g[N]; int n, sz[N], mc[N], r;
void dfs(int u, int fa) {
    sz[u] = 1; for (int v : g[u]) if (v != fa) {
        dfs(v, u), sz[u] += sz[v], mc[u] = max(mc[u], sz[v]);
    } mc[u] = max(mc[u], n - sz[u]);
    if (mc[u] < mc[r] || (mc[u] == mc[r] && u < r)) r = u;
} void solve() {
    r = 0, mc[0] = 2e9; dfs(1, -1); printf("%d\n%d\n", r, mc[r]);
}

int main() {
    n = rr; int u, v;
    for (int i = 1; i < n; ++i) u = rr, v = rr, g[u].push_back(v), g[v].push_back(u);
    solve();
    return 0;
}