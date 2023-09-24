#include <bits/stdc++.h>

#define rr read()
#define ur uread()

using namespace std;

const int N = 5e4 + 10;
const int INF = 1e9;

signed read() {
    signed num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

struct matrix {
    int a[3][3];
    matrix operator *(const matrix &t) const {
        matrix r;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            r.a[i][j] = -INF; for (int k = 0; k < 3; ++k)
                r.a[i][j] = max(r.a[i][j], a[i][k] + t.a[k][j]); }
        return r;
    }
};

void print(const matrix &t) {
    for (int i = 0; i < 3; ++i, putchar('\n')) for (int j = 0; j < 3; ++j)
        printf("%d ", t.a[i][j]);
}

const matrix I = {{0, -INF, -INF, -INF, 0, -INF, -INF, -INF, 0}};

int n, t[N];

matrix a[N];
matrix s[4 * N];

void _build(int k, int l, int r) {
    if (l == r) { s[k] = a[l]; return; }
    int mid = l + r >> 1; _build(k * 2, l, mid), _build(k * 2 + 1, mid + 1, r);
    s[k] = s[k * 2] * s[k * 2 + 1];
}

void _modify(int k, int l, int r, int x) {
    if (l > x || r < x) return;
    if (l == r && l == x) { s[k] = a[x]; return; }
    int mid = l + r >> 1; _modify(k * 2, l, mid, x), _modify(k * 2 + 1, mid + 1, r, x);
    s[k] = s[k * 2] * s[k * 2 + 1];
}

matrix _query(int k, int l, int r, int x, int y) {
    if (l > y || r < x) return I;
    if (l >= x && r <= y) return s[k];
    int mid = l + r >> 1;
    return _query(k * 2, l, mid, x, y) * _query(k * 2 + 1, mid + 1, r, x, y);
}

matrix tobase(int k) {
    matrix r = {k, k, -INF, -INF, 0, -INF, k, k, 0};
    return r;
}

void build() {
    for (int i = 1; i <= n; ++i) a[i] = tobase(t[i]);
    _build(1, 1, n);
}

int calc(int l, int r) {
    if (l == r) return t[l];
    matrix base = _query(1, 1, n, l + 1, r);
    return max({base.a[0][1] + t[l], base.a[1][1] + t[l], base.a[2][1]});
}

void modify(int x, int y) {
    t[x] = y, a[x] = tobase(y);
    _modify(1, 1, n, x);
}

int main() {
    n = ur; for (int i = 1; i <= n; ++i) t[i] = rr;
    build();
    int q = ur; for (int i = 1; i <= q; ++i) {
        int op = ur, x = ur, y = rr;
        if (op) printf("%d\n", calc(x, y));
        else modify(x, y);
    }
    return 0;
}
