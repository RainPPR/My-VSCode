#include <bits/stdc++.h>

using namespace std;

#define rr read()
#define rep(i, n) for (int i = 0; i < int(n); ++i)

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using heap = priority_queue<pli, vector<pli>, greater<pli>>;

const int N = 2e4 + 10;
const int K = 110;
const ll INF = 4e18;

inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

int n, m, k;

vector<vector<pii>> g;

void add(int u, int v, int w) {
    g[u].push_back({v, w});
}

bool vis[N][K]; ll dis[N][K];

ll dijkstra(int st, int ed) {
    rep(i, n) rep(j, k) dis[i + 1][j] = INF;
    heap q; q.push({0, st}); while (q.size()) {
        ll d; int u; tie(d, u) = q.top(); q.pop();
        if (vis[u][d % k]) continue;
        vis[u][d % k] = 1; for (pii i : g[u]) {
            int v, w; tie(v, w) = i;
            ll t = (d >= w) ? (d + 1) : ((w - d + k - 1) / k * k + d + 1);
            if (dis[v][t % k] > t) dis[v][t % k] = t, q.push({t, v});
        }
    } return vis[ed][0] ? dis[ed][0] : -1;
}

signed main() {
    n = rr, m = rr, k = rr; g.resize(n + 1);
    int u, v; rep(i, m) u = rr, v = rr, add(u, v, rr);
    printf("%lld\n", dijkstra(1, n));
    return 0;
}
