#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr(x) read<x>()
template<typename _tp>
inline _tp read() {
    _tp num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int Q = 1e5 + 10;

int n, m, q;

struct edge {
    int u, v, w;
    friend bool operator <(const edge &a, const edge &b) { return a.w > b.w; }
} g[M];

struct query {
    int id, k, v;
    friend bool operator <(const query &a, const query &b) { return a.k > b.k; }
} e[Q];

int f[N], s[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) f[x] = y, s[y] += s[x];
}

int res[Q];
int ans[Q];

void solve() {
    for (int i = 1; i <= n; ++i) f[i] = i, s[i] = 1;
    int now = 1e9, po = 1;
    for (int i = 1; i <= q; ++i) {
        while (po <= n && g[po].w >= e[i].k) merge(g[po].u, g[po].v), ++po;
        res[i] = s[find(e[i].v)] - 1;
        now = e[i].k;
    }
}

int main() {
    n = rr(int), q = rr(int), m = n - 1;
    for (int i = 1; i <= m; ++i) g[i].u = rr(int), g[i].v = rr(int), g[i].w = rr(int);
    sort(g + 1, g + m + 1);
    for (int i = 1; i <= q; ++i) e[i].id = i, e[i].k = rr(int), e[i].v = rr(int);
    sort(e + 1, e + q + 1);
    solve();
    for (int i = 1; i <= q; ++i) ans[e[i].id] = res[i];
    for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    return 0;
}
