#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

const int N = 1010;
const int INF = 0x3f3f3f3f;

struct point { int x, y; } a[N];

int f[N][N], d[N][N];

inline int get(int i, int j, int k) {
    return f[i][k] + f[k + 1][j] + (a[k].y - a[j].y) + (a[k + 1].x - a[i].x);
}

int main() {
    int n; while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            a[i].x = rr, a[i].y = rr;
            f[i][i] = 0; f[i - 1][i] = (a[i].x - a[i - 1].x) + (a[i - 1].y - a[i].y); d[i - 1][i] = i - 1;
        } for (int len = 3; len <= n; ++len) for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1; f[l][r] = INF;
            for (int k = d[l][r - 1]; k <= d[l + 1][r]; ++k) if (get(l, r, k) < f[l][r]) f[l][r] = get(l, r, k), d[l][r] = k;
        } printf("%d\n", f[1][n]);
    } return 0;
}
