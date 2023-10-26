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

#define rr read()
#define ur uread()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 int128;
typedef unsigned __int128 uint128;

template<typename _Tp> _Tp _max(const _Tp a, const _Tp b) { return a > b ? a : b; }
template<typename _Tp> _Tp _min(const _Tp a, const _Tp b) { return a < b ? a : b; }
template<typename _Tp> _Tp _abs(const _Tp x) { return x < 0 ? -x : x; }

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

const int N = 110;
const int H = 210;

struct tr {
    int t, v, h;
    bool operator <(const tr &a) const { return t < a.t; }
} a[N];

int dp[N][H];

signed main() {
    int d = ur, n = ur;
    gore(int, i, 1, n) a[i].t = ur, a[i].v = ur, a[i].h = ur;
    sort(a + 1, a + 1 + n); int maxt = 0; dp[0][0] = 10;
    gore(int, i, 1, n) gore (int, j, 0, d) {
        if (dp[i - 1][j] >= a[i].t) dp[i][j] = _max(dp[i][j], dp[i - 1][j] + a[i].v);
        if (j >= a[i].h && dp[i - 1][j - a[i].h] >= a[i].t) dp[i][j] = _max(dp[i][j], dp[i - 1][j - a[i].h]);
        maxt = _max(maxt, dp[i][j]);
    }
    int res = -1; gore(int, i, 1, n) if (dp[i][d] >= a[i].t) { res = i; break; }
    if (res == -1) printf("%d\n", maxt), meow("WOW1");
    else printf("%d\n", a[res].t), meow("WOW2");
    return 0;
}
