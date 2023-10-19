#include <bits/stdc++.h>

using namespace std;

using db = double;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max(a, b) _max(a, b)
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min(a, b) _min(a, b)
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs(x) _abs(x)
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int N = 2e5 + 10;

const db eps = 1e-10;
const db INF = 1e18;

int n, m;
struct node {
    int v, b, c;
};

vector<node> g[N];

db f[N];
bool check(db x) {
    for (int i = 1; i <= n; ++i) f[i] = -INF;
    f[1] = 0; for (int i = 1; i <= n; ++i)
        for (node j : g[i]) f[j.v] = max(f[j.v], f[i] + j.b - j.c * x);
    return f[n] > 0;
}

signed main() {
    n = rr, m = rr;
    for (int i = 1, u, v, b, c; i <= m; ++i) {
        u = rr, v = rr, b = rr, c = rr;
        g[u].push_back({v, b, c});
    } db l = 0, r = 1e4; while (r - l > eps) {
        db mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    } printf("%.15lf", l);
    return 0;
}
