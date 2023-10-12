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
inline int _min(const int a, const int b, const int c) { return _min(_min(a, b), c); }

const int N = 1e4 + 10;

vector<int> g[N];
inline void add(const int u, const int v) { g[u].push_back(v), g[v].push_back(u); }

int f[N][3];
void dfs(int u, int fa) {
    int p = 2e9; bool flag = 1;
    f[u][0] = 1, f[u][1] = f[u][2] = 0;
    for (int v : g[u]) if (v != fa) {
        dfs(v, u);
        f[u][0] += min(f[v][0], f[v][1], f[v][2]);
        f[u][1] += min(f[v][0], f[v][2]);
        if (f[v][0] <= f[v][2]) { f[u][2] += f[v][0], flag = 0; }
        else { f[u][2] += f[v][2], p = min(p, f[v][0] - f[v][2]); }
    } if (flag) f[u][2] += p;
}

int main() {
    int n = rr; for (int i = 1; i < n; ++i) add(rr, rr);
    dfs(1, -1);
    printf("%d\n", min(f[1][0], f[1][2]));
    return 0;
}
