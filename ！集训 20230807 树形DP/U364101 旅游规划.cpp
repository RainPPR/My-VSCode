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

#define _tt(x) template<typename x>
#define gg exit(0)

#define max _max
_tt(tp) inline tp _max(const tp a, const tp b) { return a > b ? a : b; }
#define min _min
_tt(tp) inline tp _min(const tp a, const tp b) { return a < b ? a : b; }
#define abs _abs
_tt(tp) inline tp _abs(const tp a) { return a < 0 ? -a : a; }

const int N = 2e5 + 10;

vector<int> g[N];
inline void add(const int u, const int v) {
    g[u].push_back(v), g[v].push_back(u);
}

int m1[N], m2[N];
int c1[N], res;

void dfs1(int u, int fa) {
    for (int v : g[u]) if (v != fa) {
        dfs1(v, u); int d = m1[v] + 1;
        if (d > m1[u]) m2[u] = m1[u], m1[u] = d, c1[u] = v;
        else if (d > m2[u]) m2[u] = d;
    } res = max(res, m1[u] + m2[u]);
}

int up[N];

void dfs2(int u, int fa) {
    for (int v : g[u]) if (v != fa) {
        if (v == c1[u]) up[v] = max(up[u], m2[u]) + 1;
        else up[v] = max(up[u], m1[u]) + 1;
        dfs2(v, u);
    }
}

int main() {
    int n = rr; for (int i = 1; i < n; ++i) add(rr, rr);
    dfs1(0, -1); dfs2(0, -1);
    for (int i = 0; i <= n; ++i) {
        if (m1[i] + max(m2[i], up[i]) == res) printf("%d\n", i);
    } return 0;
}
