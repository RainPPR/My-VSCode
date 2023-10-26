#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

#define rr(x) read<x>()
#define ri rr(int)
#define rl rr(ll)

#define gor(i, n) for (int i = 0; i < (n); ++i)

template<typename tp>
inline tp read() {
    tp num = 0; int flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

const ll INF = 4e18;

class graph {
private:
    int n; vector<vector<pii>> g;
    vector<ll> dis; vector<bool> st;
    void dijkstra(int s) {
        priority_queue<pli, vector<pli>, greater<pli>> heap;
        heap.push({0, s}); dis[s] = 0;
        ll d; int u, v, w;
        while (heap.size()) {
            tie(d, u) = heap.top(); heap.pop();
            if (st[u]) continue; st[u] = true;
            for (pii i : g[u]) {
                tie(v, w) = i; if (dis[v] > d + w)
                dis[v] = d + w, heap.push({dis[v], v});
            }
        }
    }
public:
    graph(int _n) {
        n = _n, g = vector<vector<pii>>(n + 1);
    } void add(int u, int v, int w) {
        g[u].push_back({v, w});
    } void dijk(int s) {
        dis = vector<ll>(n + 1, INF), st = vector<bool>(n + 1); dijkstra(s);
    } ll getdis(int t) {
        return dis[t] == INF ? -1 : dis[t];
    }
};

#define getedge() int u = ri, v = ri, w = ri

int n, m;

void add(graph &g, int u, int v, int w) {
    #define add g.add
    add(u, v + 3 * n, w), add(u, v, w), add(u + n, v + n, w), add(u + 2 * n, v + 2 * n, w), add(u + 3 * n, v + 3 * n, w);
    add(u, v + n, 0), add(u + 2 * n, v + 3 * n, 0), add(u, v + 2 * n, 2 * w), add(u + n, v + 3 * n, 2 * w);
    #undef add
}

signed main() {
    n = ri, m = ri; graph g(4 * n); while (m--) {
        getedge(); add(g, u, v, w), add(g, v, u, w);
    } g.dijk(1); for (int i = 2; i <= n; ++i) printf("%lld ", g.getdis(i + 3 * n));
    return 0;
}
