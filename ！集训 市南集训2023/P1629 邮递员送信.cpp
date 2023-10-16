#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pli = pair<ll, int>;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

const int N = 1e3 + 10;
const int M = 1e5 + 10;

struct graph {
    int h[N], e[M], ne[M], w[M], idx;
    graph() { memset(h, -1, sizeof h); }
    void add(const int u, const int v, const int x) { e[idx] = v, w[idx] = x, ne[idx] = h[u], h[u] = idx++; }
    int st[N]; ll dis[N]; void dijkstra(int);
} g[2];

void graph::dijkstra(int s) {
    memset(dis, 0x3f, sizeof dis);
    priority_queue<pli, vector<pli>, greater<pli>> heap;
    heap.push({0, s}); while (heap.size()) {
        pli now = heap.top(); heap.pop(); int u = now.second; ll d = now.first;
        if (st[u]) continue; st[u] = 1;
        for (int i = h[u]; ~i; i = ne[i]) if (dis[e[i]] > d + w[i])
            dis[e[i]] = d + w[i], heap.push({dis[e[i]], e[i]});
    }
}

signed main() {
    int n = rr, m = rr, u, v, w;
    for (int i = 1; i <= m; ++i) u = rr, v = rr, w = rr, g[0].add(u, v, w), g[1].add(v, u, w);
    g[0].dijkstra(1), g[1].dijkstra(1);
    ll res = 0; for (int i = 2; i <= n; ++i) res += g[0].dis[i] + g[1].dis[i];
    printf("%lld\n", res); return 0;
}
