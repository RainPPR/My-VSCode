#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline ll read() {
    ll n = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + c - '0';
    return n * f;
}

inline ll getdis(ll xa, ll ya, ll xb, ll yb) {
    return abs(xa - xb) + abs(ya - yb);
}

int main() {
    ll xa = rr, ya = rr, xb = rr, yb = rr, xc = rr, yc = rr;
    // 箱子与目标 重合
    if (xb == xc && yb == yc) { printf("0\n"); }
    // 箱子在目标 上
    if (xb == xc && yb < yc) { printf("%lld\n", yc - yb + getdis(xa, ya, xb, yb - 1) + 2 * (xa == xb && ya > yb)); }
    // 箱子在目标 下
    if (xb == xc && yb > yc) { printf("%lld\n", yb - yc + getdis(xa, ya, xb, yb + 1) + 2 * (xa == xb && ya < yb)); }
    // 箱子在目标 左
    if (yb == yc && xb < xc) { printf("%lld\n", xc - xb + getdis(xa, ya, xb - 1, yb) + 2 * (ya == yb && xa > xb)); }
    // 箱子在目标 右
    if (yb == yc && xb > xc) { printf("%lld\n", xb - xc + getdis(xa, ya, xb + 1, yb) + 2 * (ya == yb && xa < xb)); }
    // 箱子在目标 左上
    if (xb < xc && yb < yc) { printf("%lld\n", xc - xb + yc - yb + 2 + min(getdis(xa, ya, xb, yb - 1) + 2 * (xa == xb && ya > yb), getdis(xa, ya, xb - 1, yb) + 2 * (ya == yb && xa > xb))); }
    // 箱子在目标 左下
    if (xb < xc && yb > yc) { printf("%lld\n", xc - xb + yb - yc + 2 + min(getdis(xa, ya, xb, yb + 1) + 2 * (xa == xb && ya < yb), getdis(xa, ya, xb - 1, yb) + 2 * (ya == yb && xa > xb))); }
    // 箱子在目标 右上
    if (xb > xc && yb < yc) { printf("%lld\n", xb - xc + yc - yb + 2 + min(getdis(xa, ya, xb + 1, yb) + 2 * (ya == yb && xa < xb), getdis(xa, ya, xb, yb - 1) + 2 * (xa == xb && ya > yb))); }
    // 箱子在目标 右下
    if (xb > xc && yb > yc) { printf("%lld\n", xb - xc + yb - yc + 2 + min(getdis(xa, ya, xb + 1, yb) + 2 * (ya == yb && xa < xb), getdis(xa, ya, xb, yb + 1) + 2 * (xa == xb && ya < yb))); }
    return 0;
}
