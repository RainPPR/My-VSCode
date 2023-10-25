#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define rc readchar()
inline int readchar() {
    int ch = getchar();
    while (ch == '\n' || ch == '\r' || ch == ' ') ch = getchar();
    return ch;
}

#define tp(t) template<typename t> inline t

#define max _max
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int N = 5010;
const int MOD = 998244353;

int f[N];

int main() {
    int q = rr, k = rr;
    f[0] = 1; while (q--) {
        int op = rc, a = rr;
        if (op == '+') for (int i = k; i >= a; --i) f[i] = (f[i] + f[i - a]) % MOD;
        else for (int i = a; i <= k; ++i) f[i] = (f[i] - f[i - a] + MOD) % MOD;
        printf("%d\n", f[k]);
    } return 0;
}
