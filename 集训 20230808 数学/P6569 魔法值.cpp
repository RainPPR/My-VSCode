#include <bits/stdc++.h>

#define rr read()
#define ur uread()

using namespace std;

typedef long long ll;

const int N = 110;
const int K = 35;

ll read() {
    ll num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

ll uread() {
    ll num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

struct matrix {
    int n, m; ll a[N][N];
    matrix operator *(const matrix t) const {
        matrix r = {n, t.m, {0}};
        for (int i = 0; i < n; ++i) for (int j = 0; j < t.m; ++j)
            for (int k = 0; k < m; ++k) r.a[i][j] = (r.a[i][j] + a[i][k] * t.a[k][j]) & 1;
        return r;
    }
};

ll a[N];
matrix g[K];

signed main() {
    int n = ur, m = ur, q = ur; g[0] = {n, n, {0}};
    for (int i = 0; i < n; ++i) a[i] = ur;
    int u, v; for (int i = 0; i < m; ++i) u = ur - 1, v = ur - 1, g[0].a[u][v] = g[0].a[v][u] = 1;
    for (int i = 1; i < K; ++i) g[i] = g[i - 1] * g[i - 1];
    while (q--) {
        ll d = ur; matrix r = {1, n, {1}};
        for (int i = 0; d; d >>= 1, ++i) if (d & 1) r = r * g[i];
        ll s = 0; for (int i = 0; i < n; ++i) if (r.a[0][i]) s ^= a[i];
        printf("%lld\n", s);
    }
    return 0;
}
