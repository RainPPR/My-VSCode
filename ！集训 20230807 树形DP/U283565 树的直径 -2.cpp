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

vector<int> g[N]; int res;
int dfs(int u, int fa) { // 返回以 u 为 lca 的树的直径
    int m1 = 0, m2 = 0;
    for (int v : g[u]) {
        if (v == fa) continue;
        int d = dfs(v, u) + 1;
        if (d >= m1) m2 = m1, m1 = d;
        else if (d >= m2) m2 = d;
    } res = max(res, m1 + m2);
    return m1;
} int solve() {
    res = 0; dfs(1, -1); return res;
} // 树形 DP

int main() {
    int n = rr, u, v; for (int i = 1; i < n; ++i) u = rr, v = rr, g[u].push_back(v), g[v].push_back(u);
    printf("%d\n", solve());
    return 0;
}