#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int pos1, n, k, v, dp[N], ans;
vector<int> g[N];
void dfs(int u, int fa) {
    dp[u] = 1; for (int v : g[u]) dfs(v, u), dp[u] = max(dp[u], dp[v] + 1);
    if ((u != 1) && (dp[u] > k || (dp[u] == k && fa != 1))) ++ans, dp[u] = 0;
} signed main() {
    cin >> n >> k >> pos1;
    for (int i = 2; i <= n; ++i) cin >> v, g[v].push_back(i);
    dfs(1, -1); printf("%d\n", ans + (pos1 != 1));
    return 0;
}