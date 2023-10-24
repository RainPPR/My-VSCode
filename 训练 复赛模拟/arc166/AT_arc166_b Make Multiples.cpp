#include <bits/stdc++.h>

using std::min;
using ll = long long;

#define gcd(a, b) std::__gcd(a, b)
#define lcm(a, b) ((a) / gcd(a, b) * (b))

#define rr(x) read<x>()
template<typename tp> inline tp read() {
    tp num = 0, flag = 1;
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

const int N = 2e5 + 10;
const ll INF = 4e18;

ll A[N], f[N][8];
inline ll to(ll x, ll y) { return (x + y - 1) / y * y - x; }

int main() {
    int n = rr(int);
    ll a = rr(ll), b = rr(ll), c = rr(ll), ab = lcm(a, b), bc = lcm(b, c), ac = lcm(a, c), abc = lcm(ab, c);
    f[0][0] = 0; for (int i = 1; i < 8; ++i) f[0][i] = INF;
    for (int i = 1; i <= n; ++i) A[i] = rr(ll);
    for (int i = 1; i <= n; ++i) {
        f[i][0b000] = f[i - 1][0b000];
        f[i][0b001] = min({f[i - 1][0b001], f[i - 1][0b000] + to(A[i], a)});
        f[i][0b010] = min({f[i - 1][0b010], f[i - 1][0b000] + to(A[i], b)});
        f[i][0b100] = min({f[i - 1][0b100], f[i - 1][0b000] + to(A[i], c)});
        f[i][0b011] = min({f[i - 1][0b011], f[i - 1][0b001] + to(A[i], b), f[i - 1][0b010] + to(A[i], a), f[i - 1][0b000] + to(A[i], ab)});
        f[i][0b101] = min({f[i - 1][0b101], f[i - 1][0b001] + to(A[i], c), f[i - 1][0b100] + to(A[i], a), f[i - 1][0b000] + to(A[i], ac)});
        f[i][0b110] = min({f[i - 1][0b110], f[i - 1][0b010] + to(A[i], c), f[i - 1][0b100] + to(A[i], b), f[i - 1][0b000] + to(A[i], bc)});
        f[i][0b111] = min({f[i - 1][0b111], f[i - 1][0b011] + to(A[i], c), f[i - 1][0b101] + to(A[i], b), f[i - 1][0b110] + to(A[i], a), f[i - 1][0b001] + to(A[i], bc), f[i - 1][0b010] + to(A[i], ac), f[i - 1][0b100] + to(A[i], ab), f[i - 1][0b000] + to(A[i], abc)});
    } printf("%lld\n", f[n][7]);
    return 0;
}
