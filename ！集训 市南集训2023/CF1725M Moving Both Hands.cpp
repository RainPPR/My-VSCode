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

const int N = 1e5 + 10;
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

signed main() {
    int n = ri, m = ri; graph g(n + n);
    for (int i = 1; i <= n; ++i) g.add(i, i + n, 0);
    while (m--) { getedge(); g.add(u, v, w), g.add(v + n, u + n, w); }
    g.dijk(1); for (int i = 2; i <= n; ++i) printf("%lld ", g.getdis(i + n));
    return 0;
}
