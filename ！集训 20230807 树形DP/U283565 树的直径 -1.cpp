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

vector<int> g[N]; int c, d[N];
void dfs(int u, int fa) {
    for (int v : g[u])
        if (v != fa) { if ((d[v] = d[u] + 1) > d[c]) c = v; dfs(v, u); }
} inline int solve() {
    d[1] = 0, c = 1; dfs(1, -1);
    d[c] = 0; dfs(c, -1);
    return d[c];
} // Á½±é DFS

int main() {
    int n = rr, u, v; for (int i = 1; i < n; ++i) u = rr, v = rr, g[u].push_back(v), g[v].push_back(u);
    printf("%d\n", solve());
    return 0;
}