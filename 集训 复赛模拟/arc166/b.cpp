#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline ll read() {
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

const int N = 2e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n;
ll e[4], a[N];

ll f[4][N], g[N][1 << 3];

int main() {
    n = rr, e[1] = rr, e[2] = rr, e[3] = rr;
    for (int i = 1; i <= n; ++i) {
        a[i] = rr; for (int j = 1; j <= 3; ++j) f[j][i] = a[i] % e[j] ? (a[i] / e[j] + 1) * e[j] - a[i] : 0;
    } 
    
    memset(g, 0x3f, sizeof g); g[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int s = 0; s < (1 << 3); ++s) {
            if (g[i][s] == INF) {
                set<ll> gabc;
                if (s & 1) gabc.insert(f[1][i + 1]);
                if (s & 2) gabc.insert(f[2][i + 1]);
                if (s & 4) gabc.insert(f[3][i + 1]);
                if (gabc.empty()) g[i][s] = 0;
                else {
                    auto k = gabc.begin();
                    ll t = *k; ++k;
                    for (; k != gabc.end(); ++k) t = *k / __gcd(t, *k) * t;
                    g[i][s] = t;
                }
            }
            cerr << "| " << g[i][s] << ": " << endl;
            for (int u = 0; u < (1 << 3); ++u) {
                // if (s & u) continue;
                if (s == (s | u) && u != 0) continue;
                if ((u & 1) && (u & 2) && (f[1][i + 1] != f[2][i + 1])) continue;
                if ((u & 1) && (u & 4) && (f[1][i + 1] != f[3][i + 1])) continue;
                if ((u & 2) && (u & 4) && (f[2][i + 1] != f[3][i + 1])) continue;
                ll cost = 0; set<ll> cabc;
                if (u & 1) cabc.insert(f[1][i + 1]);
                if (u & 2) cabc.insert(f[2][i + 1]);
                if (u & 4) cabc.insert(f[3][i + 1]);
                for (int k : cabc) cost += k;
                cerr << i + 1 << " " << (s | u) << ": " << cost << endl;
                g[i + 1][s | u] = min(g[i + 1][s | u], g[i][s] + cost);
            }
        }
    }
    
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= n; ++j) printf("%d ", f[i][j]);
        putchar('\n');
    } putchar('\n');
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < (1 << 3); ++s) printf("%d ", g[i][s]);
        putchar('\n');
    }
    return 0;
}