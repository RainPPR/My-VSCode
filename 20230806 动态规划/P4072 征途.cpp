#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

const int N = 3010;

int n, m, s[N];
int f[N], d[N], v[N];

pair<int, int> solve(int ad) {
    memset(f, 0x3f, sizeof f);
    f[0] = d[0] = v[0] = 0;
    for (int i = 1; i <= n; ++i) for (int j = 0; j < i; ++j) {
        int nw = f[j] + (s[i] - s[j]) * (s[i] - s[j]) + ad;
        if (nw < f[i] || (nw == f[i] && d[i] > d[j] + 1)) f[i] = nw, d[i] = d[j] + 1, v[i] = j;
    } return {f[n], d[n]};
}

signed main() {
    n = rr, m = rr; for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + rr;
    int ad, l = -1e9, r = 1e9; while (l < r) {
        pair<int, int> ans0 = solve(ad = l + r >> 1);
        if (ans0.second > m) l = ad + 1; else r = ad;
    } pair<int, int> ans = solve(l);
    printf("%d\n", m * (ans.first - l * m) - s[n] * s[n]);
    return 0;
}