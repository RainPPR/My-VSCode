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

const int N = 1010;

int n, g[N][N];

struct dijk {
    int vis[N]; ll dis[N];
    dijk(int s, int k, int b) {
        memset(dis, 0x3f, sizeof dis); dis[s] = 0;
        for (int i = 1; i <= n; ++i) {
            int t = -1; for (int j = 1; j <= n; ++j)
                if (!vis[j] && (t == -1 || dis[j] < dis[t])) t = j;
            vis[t] = 1; for (int j = 1; j <= n; ++j)
                dis[j] = min(dis[j], dis[t] + 1ll * g[t][j] * k + b);
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
