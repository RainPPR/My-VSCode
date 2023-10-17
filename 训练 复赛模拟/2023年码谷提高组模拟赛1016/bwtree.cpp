#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
multiset<int> g[100010];
map<pii, int> st;
queue<pii> q;
void add(int u, int v) {
    if (u == v) return;
    if (u > v) swap(u, v);
    g[u].insert(v), g[v].insert(u);
    if (++st[{u, v}] == 2) q.push({u, v});
} bool solve() {
    int n, x, y; scanf("%d\n", &n);
    st.clear(); while (q.size()) q.pop();
    for (int i = 1; i <= n + n - 2; ++i) g[i].clear();
    for (int i = 1; i <= n + n - 2; ++i) scanf("%d %d", &x, &y), add(x, y);
    int s = 0; while (q.size() && s < n - 1) {
        if (!st[q.front()]) { q.pop(); continue; }
        pii now = q.front(); q.pop();
        int &u = now.first, &v = now.second;
        if (g[u].size() < g[v].size()) swap(u, v);
        for (int t : g[v]) st[minmax(t, v)] = 0, g[t].erase(g[t].find(v)), add(u, t);
        g[v].clear(); ++s;
    } return s == n - 1;
} signed main() {
    int T; scanf("%d\n", &T); while (T--) {
        printf(solve() ? "YES\n" : "NO\n");
    } return 0;
}
