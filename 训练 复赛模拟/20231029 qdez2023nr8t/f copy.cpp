#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

const int N = 2e6 + 10;

vector<int> g[N]; void add(int u, int v) {
    g[u].push_back(v), g[v].push_back(u);
}

int f[N]; void dfs(int u, int fa) {
    f[u] = fa; for (int v : g[u]) if (v != fa) dfs(v, u);
}

signed main() {
    int n = rr; for (int i = 1; i < n; ++i) add(rr, rr);
    dfs(1, -1); int s = rr, k; set<int> d[2];
    for (int i = 1; i <= s; ++i) k = rr, d[0].emplace(f[k]);
    for (int k = 1; !d[k ^ 1].count(-1); k ^= 1) {
        printf("%d ", (int)d[k ^ 1].size()); d[k].clear();
        for (auto i : d[k ^ 1]) d[k].emplace(f[i]);
    } return 0;
}
