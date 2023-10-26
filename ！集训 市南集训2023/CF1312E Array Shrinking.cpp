#include <bits/stdc++.h>

using namespace std;

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

#define r (l + len - 1)

const int N = 510;
const int INF = 1e9;

int q[N];
int f[N][N], g[N];

signed main() {
    int n = ri; for (int i = 1; i <= n; ++i) q[i] = ri, f[i][i] = q[i];
    for (int len = 2; len <= n; ++len) for (int l = 1; l + len - 1 <= n; ++l)
        for (int k = l; k < r; ++k) if (f[l][k] != 0 && f[l][k] == f[k + 1][r]) f[l][r] = max(f[l][r], f[l][k] + 1);
    g[0] = 0; for (int i = 1; i <= n; ++i) {
        g[i] = INF; for (int j = 1; j <= i; ++j) if (f[j][i]) g[i] = min(g[i], g[j - 1] + 1);
    } printf("%d\n", g[n]);
    return 0;
}
