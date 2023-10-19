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

const int N = 1e6 + 10;

using ll = long long;

int h[N], e[N << 1], ne[N << 1], idx;
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
    e[idx] = u, ne[idx] = h[v], h[v] = idx++;
}

int c[N], vis[N];

int k, cl, cr;
void cir(int u, int fa) {
    vis[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int &v = e[i]; if (v == fa) continue;
        if (vis[v]) { cl = u, cr = v, k = i; }
        else cir(v, u);
    }
}

ll f[N][2];
ll dfs(int u, int fa) {
    vis[u] = 1; f[u][0] = 0, f[u][1] = c[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        if (i == k || (i ^ 1) == k) continue;
        int &v = e[i]; if (v == fa) continue;
        f[u][1] += dfs(v, u); f[u][0] += max(f[v][0], f[v][1]);
    } return f[u][0];
}

inline ll solve(int x) {
    cir(x, -1);
    ll t1 = dfs(cl, -1);
    ll t2 = dfs(cr, -1);
    return max(t1, t2);
}

signed main() {
    memset(h, -1, sizeof h);
    int n = rr; for (int i = 1; i <= n; ++i) c[i] = rr, add(i, rr);
    ll ans = 0; for (int i = 1; i <= n; ++i) if (!vis[i]) ans += solve(i);
    printf("%lld\n", ans);
    return 0;
}
