#include <bits/stdc++.h>

#define rr read()
#define ur uread()
#define _rr(x) x = read()
#define _ur(x) x = uread()

#define getu(d) d[0] = ur, d[1] = ur, d[2] = ur, d[3] = ur

using namespace std;

typedef long long ll;

signed read() {
    signed num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
} unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

const int N = 1e5 + 10;

ll f[N];

int c[4], d[4];
inline ll cz(int id) { return 1ll * c[id] * (d[id] + 1); }

signed main() {
    getu(c); int q = ur;
    f[0] = 1; for (int j = 0; j < 4; ++j) for (int i = c[j]; i < N; ++i) f[i] += f[i - c[j]];
    while (q--) {
        getu(d); int s = ur;
        ll sum = 0; for (int i = 0; i <= 15; ++i) {
            int e = 0; ll res = s;
            for (int t = i, j = 0; t; t >>= 1, ++j) if (t & 1) e ^= 1, res -= cz(j);
            if (res >= 0) e ? sum -= f[res] : sum += f[res];
        } printf("%lld\n", sum);
    } return 0;
}
