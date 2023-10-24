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

const int N = 2010;

int n;
ll g[N][N];

struct dijk {
    int vis[N]; ll dis[N];
    dijk(int s) {
        memset(dis, 0x3f, sizeof dis);
        hp(pli) heap; heap.push({0, s});
        dis[s] = 0; ll d; int u;
        while (heap.size()) {
            tie(d, u) = heap.top(); heap.pop();
            if (vis[u]) continue; vis[u] = 1;
            for (int v = 1; v <= n; ++v) if (v != u && dis[v] > d + g[u][v]) 
                dis[v] = d + g[u][v], heap.push({dis[v], v});
        }
    }
};

signed main() {
    memset(g, 0x3f, sizeof g);
    n = rr; int a = rr, b = rr, c = rr, u, v, x;
    for (int i = 1; i <= n; ++i) g[i][i + n] = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        x = rr, g[i][j] = 1ll * a * x, g[i + n][j + n] = 1ll * b * x + c;
    } n <<= 1; dijk d(1); printf("%lld\n", d.dis[n]);
    return 0;
}
