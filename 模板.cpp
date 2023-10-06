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
#define _rr(x) x = read()
#define _ur(x) x = uread()

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
} unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

signed main() {
    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);
    int n = ur;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
