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

const int N = 1510;

vector<int> g[N];
inline void add(const int u, const int v) { 
    g[u].push_back(v), g[v].push_back(u); }

int f[N][2];
void dfs(int u, int fa) {
    f[u][0] = 0, f[u][1] = 1;
    for (int v : g[u]) if (v != fa) {
        dfs(v, u); f[u][0] += f[v][1];
        f[u][1] += min(f[v][0], f[v][1]);
    }
}

int main() {
    int n = rr, u, v, k;
    for (int i = 0; i < n; ++i) {
        u = rr, k = rr; while (k--) add(u, rr);
    } dfs(0, -1); printf("%d\n", min(f[0][0], f[0][1]));
    return 0;
}
