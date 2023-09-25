#include <bits/stdc++.h>

#define gor(_Tp, x, s, t) for (_Tp x = s; x < t; ++x)
#define gore(_Tp, x, s, t) for (_Tp x = s; x <= t; ++x)
#define rgor(_Tp, x, s, t) for (_Tp x = s; x > t; --x)
#define rgore(_Tp, x, s, t) for (_Tp x = s; x >= t; --x)
#define _gor(_Tp, x, s, t, p) for (_Tp x = s; x < t; x += p)
#define _gore(_Tp, x, s, t, p) for (_Tp x = s; x <= t; x += p)
#define _rgor(_Tp, x, s, t, p) for (_Tp x = s; x > t; x -= p)
#define _rgore(_Tp, x, s, t, p) for (_Tp x = s; x >= t; x -= p)

#define debug(x) cerr << #x << " = " << x << endl
#define meow(args...) fprintf(stderr, args)

#define ur uread()

using namespace std;

template<typename _Tp> _Tp _max(const _Tp a, const _Tp b) { return a > b ? a : b; }
template<typename _Tp> _Tp _min(const _Tp a, const _Tp b) { return a < b ? a : b; }
template<typename _Tp> _Tp _abs(const _Tp x) { return x < 0 ? -x : x; }

unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

const int N = 110;
const int M = 3010;

int pw[N];
const int op[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int a[N];
int f[N][M];

void solve(int n, int m, const int cs) {
    memset(f, 0x3f, sizeof f); f[0][0] = 0;
    gore(int, i, 0, n) gor(int, j, 0, m) if (f[i][j] != 0x3f3f3f3f)
        gor(int, k, 0, 10)
            f[i + 1][(j * 10 + k) % m] = _min(f[i + 1][(j * 10 + k) % m], f[i][j] + op[k]);
    int r = n; while (r && f[r][0] > n) --r;
    if (r == 0) { printf("Case %d: -1\n", cs); return; }
    pw[0] = 1; gor(int, i, 1, r) pw[i] = pw[i - 1] * 10 % m;
    memset(a, 0, sizeof a); int o = 0, l = n;
    gor(int, i, 0, r) rgore(int, k, 9, 0) {
        int t = k * pw[r - i - 1] % m;
        if (f[r - i - 1][(m - (o + t) % m) % m] <= l - op[k]) {
            o = (o + t) % m; l -= op[k]; a[i] = k; break;
        }
    }
    printf("Case %d: ", cs);
    int i = 0; while (i < r - 1 && a[i] == 0) ++i;
    for (; i < r; ++i) printf("%d", a[i]);
    printf("\n");
}

signed main() {
    int cs = 0, n, m; while (n = ur) solve(n, ur, ++cs);
    return 0;
}
