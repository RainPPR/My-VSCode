#include <bits/stdc++.h>

using namespace std;

#define inwin 0

#define rr uread()
inline int uread() {
    int num = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

const int N = 1e5 + 10;

int n, k;
vector<int> g[N];

int dp[N], ans;
void dfs(int u, int fa) {
    dp[u] = 1; for (int v : g[u]) dfs(v, u), dp[u] = max(dp[u], dp[v] + 1);
    if (dp[u] > k || (dp[u] == k && fa != 1)) ++ans, dp[u] = 0;
}

signed main() {
    n = rr, k = rr;
    int pos1 = rr; for (int i = 2; i <= n; ++i) g[rr].push_back(i);
    dfs(1, -1); printf("%d\n", ans + (pos1 != 1));
    return 0;
}
