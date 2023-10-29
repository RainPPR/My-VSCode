#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

inline int max2(const int a, const int b) { return a > b ? a : b; }
inline int max3(const int a, const int b, const int c) { return max2(a, max2(b, c)); }
inline int max4(const int a, const int b, const int c, const int d) { return max2(max2(a, b), max2(c, d)); }

const int N = 3e5 + 10;

vector<int> g[N];

int f[N], c[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

int len;
int dfs(int u, int fa) {
    int m1 = 0, m2 = 0;
    for (int v : g[u]) {
        if (v == fa) continue;
        int d = dfs(v, u) + 1;
        if (d >= m1) m2 = m1, m1 = d;
        else if (d > m2) m2 = d;
    } len = max2(len, m1 + m2);
    return m1;
}

int main() {
    int n = rr, m = rr, q = rr;
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
    } for (int i = 1; i <= m; ++i) {
        int u = rr, v = rr; f[find(u)] = find(v);
        g[u].push_back(v), g[v].push_back(u);
    } for (int i = 1; i <= n; ++i) {
        if (f[i] != i) continue;
        len = 0; dfs(i, -1); c[i] = len;
    } while (q--) {
        int op = rr; if (op == 1) { printf("%d\n", c[find(rr)]); continue; }
        int x = find(rr), y = find(rr); if (x == y) continue;
        f[x] = y; c[y] = max3(c[x], c[y], (c[x] + 1) / 2 + (c[y] + 1) / 2 + 1);
    } return 0;
}
