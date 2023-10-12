#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

#define max _max
inline int _max(const int a, const int b) { return a > b ? a : b; }
#define min _min
inline int _min(const int a, const int b) { return a < b ? a : b; }

const int N = 1e4 + 10;

int n, k;
vector<int> g[N];

int sz[N];
vector<int> res;

void dfs(int u, int fa) {
    sz[u] = 1; int mc = 0;
    for (int v : g[u]) if (v != fa) {
        dfs(v, u), sz[u] += sz[v], mc = max(mc, sz[v]);
    } mc = max(mc, n - sz[u]);
    if (mc <= k) res.push_back(u);
}

int main() {
    n = rr, k = n >> 1;
    int u, v; for (int i = 1; i < n; ++i) u = rr, v = rr, g[u].push_back(v), g[v].push_back(u);
    dfs(1, -1); sort(res.begin(), res.end());
    for (int i : res) printf("%d\n", i);
    return 0;
}