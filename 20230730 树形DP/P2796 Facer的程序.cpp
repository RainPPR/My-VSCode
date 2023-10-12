#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

#define max _max
inline int _max(const int a, const int b) { return a > b ? a : b; }
#define min _min
inline int _min(const int a, const int b) { return a < b ? a : b; }

using ll = long long;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

vector<int> g[N];
inline void add(const int u, const int v) { g[u].push_back(v), g[v].push_back(u); }

ll dp[N];
void dfs(int u, int fa) {
    dp[u] = 1;
    for (int v : g[u]) if (v != fa) {
        dfs(v, u); dp[u] = dp[u] * ((dp[v] + 1) % MOD) % MOD;
    }
}

int main() {
    int n = rr; for (int i = 1; i < n; ++i) add(rr, rr);
    dfs(1, -1); ll r = 0;
    for (int i = 1; i <= n; ++i) r = (r + dp[i]) % MOD;
    printf("%lld\n", r);
    return 0;
}
