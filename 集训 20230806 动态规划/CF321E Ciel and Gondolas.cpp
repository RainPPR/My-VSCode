#include <bits/stdc++.h>

using namespace std;

#define rr read()
signed read() {
    signed num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

const int N = 4010;
const int M = 810;

int s[N][N];
int f[M][N];

inline int cost(const int x, const int y) { return (s[y][y] - s[y][x - 1] - s[x - 1][y] + s[x - 1][x - 1]) >> 1; }

void solve(int i, int l, int r, int p, int q) {
    if (l > r) return;
    int j = l + r >> 1, opt = 0;
    for (int t = p; t <= q && t <= j; ++t) {
        int e = f[i - 1][t] + cost(t + 1, j);
        if (f[i][j] > e) f[i][j] = e, opt = t;
    }
    solve(i, l, j - 1, p, opt);
    solve(i, j + 1, r, opt, q);
}

signed main() {
    int n = rr, k = rr;
    for (int i = 1; i <= n; ++i) for (int j = 1 ; j <= n; ++j) s[i][j] = rr + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    memset(f, 0x3f, sizeof f); f[0][0] = 0;
    for (int i = 1; i <= k; ++i) solve(i, 0, n, 0, n);
    printf("%d\n", f[k][n]);
    return 0;
}
