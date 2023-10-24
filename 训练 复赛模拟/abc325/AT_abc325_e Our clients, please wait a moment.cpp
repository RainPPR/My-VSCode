#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pli = pair<ll, int>;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

#define hp(x) priority_queue<x, vector<x>, greater<x>>

const int N = 1010;

int n;
int g[N][N];

struct dijk {
    int vis[N]; ll dis[N];
    dijk(int s, int k, int b) {
        memset(dis, 0x3f, sizeof dis);
        hp(pli) heap; heap.push({0, s});
        dis[s] = 0; ll d; int u;
        while (heap.size()) {
            tie(d, u) = heap.top(); heap.pop();
            if (vis[u]) continue; vis[u] = 1;
            for (int v = 1; v <= n; ++v) if (v != u) {
                ll nw = d + 1ll * g[u][v] * k + b;
                if (dis[v] > nw) dis[v] = nw, heap.push({dis[v], v});
            }
        }
    }
};

signed main() {
    n = rr; int a = rr, b = rr, c = rr;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) g[i][j] = rr;
    dijk f1(1, a, 0), fn(n, b, c);
    ll res = 4e18; for (int i = 1; i <= n; ++i) {
        res = min(res, f1.dis[i] + fn.dis[i]);
    } printf("%lld\n", res);
    return 0;
}
