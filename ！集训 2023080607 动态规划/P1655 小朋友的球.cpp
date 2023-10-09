#include <bits/stdc++.h>

using namespace std;

const int N = 102, M = 102;
const int Q = 1002;

struct bint
{
    signed char d[Q], cnt;

    bint() { cnt = 0; }

    bint operator =(int a) {
        while (a) d[++cnt] = a % 10, a /= 10;
        return *this;
    }

    bint operator *(const int a) {
        bint t; int tmp;
        int up = 0; for (int i = 1; i <= cnt; ++i) {
            tmp = d[i] * a + up;
            t.d[++t.cnt] = tmp % 10, up = tmp / 10;
        } while (up) t.d[++t.cnt] = up % 10, up /= 10;
        return t;
    }

    bint operator +(const bint &a) {
        bint t; int i, tmp;
        int up = 0; for (i = 1; i <= a.cnt && i <= cnt; ++i) {
            tmp = d[i] + a.d[i] + up;
            t.d[++t.cnt] = tmp % 10, up = tmp / 10;
        } for (; i <= a.cnt; ++i) {
            tmp = a.d[i] + up;
            t.d[++t.cnt] = tmp % 10, up = tmp / 10;
        } for (; i <= cnt; ++i) {
            tmp = d[i] + up;
            t.d[++t.cnt] = tmp % 10, up = tmp / 10;
        } while (up) t.d[++t.cnt] = up % 10, up /= 10;
        return t;
    }

    void print() {
        if (cnt == 0) { printf("0\n"); return; }
        int i = cnt; while (d[i] == 0) ++i;
        for (; i; --i) putchar('0' + d[i]);
        putchar('\n');
    }
};

bint f[N][M];

signed main() {
    f[0][0] = 1;
    for (int i = 1; i <= 100; ++i) for (int j = 1; j <= i; ++j) f[i][j] = f[i - 1][j - 1] + f[i - 1][j] * j;
    int n, m; while (~scanf("%d %d", &n, &m)) f[n][m].print();
    return 0;
}
