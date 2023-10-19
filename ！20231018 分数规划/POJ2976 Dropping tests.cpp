// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

using db = double;

const int N = 1010;
const db eps = 1e-6;

int n, k;
int a[N], b[N];

db c[N];
inline bool cmp(const db a, const db b) {
    return a > b;
} bool check(const db x) {
    for (int i = 1; i <= n; ++i) c[i] = a[i] - b[i] * x;
    sort(c + 1, c + n + 1, cmp); db s = 0;
    for (int i = 1; i <= n - k; ++i) s += c[i];
    return s > 0;
}

signed main() {
    while (1) {
        n = rr, k = rr; if (!n && !k) break;
        for (int i = 1; i <= n; ++i) a[i] = rr;
        for (int i = 1; i <= n; ++i) b[i] = rr;
        db l = 0, r = 100, mid; while (r - l > eps) {
            mid = (l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid;
        } printf("%d\n", int(mid * 100 + 0.5));
    } return 0;
}
