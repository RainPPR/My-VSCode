#include <bits/stdc++.h>

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

const int N = 1e6 + 10;

int a[N];
ll sl[N], sr[N];

ll solve(int l, int r) {
    if (l > r) return 0;
    sl[l - 1] = sr[r + 1] = 0;
    for (int i = l; i <= r; ++i) sl[i] = sl[i - 1] + a[i] * a[i + 1];
    for (int i = r; i >= l; --i) sr[i] = sr[i + 1] + a[i] * a[i - 1];
    ll res = 4e18; for (int i = l; i <= r; ++i) res = _min(res, sl[i - 1] + sr[i + 1] + a[i]);
    return res;
}

signed main() {
    int n = ur; a[0] = a[n + 1] = 1;
    for (int i = 1; i <= n; ++i) a[i] = ur;
    ll res = 0; int l = 1, r = 1;
    for (; r <= n + 1; ++r) if (a[r] == 1) res += solve(l, r - 1) + 1, l = r + 1;
    printf("%lld\n", res - 1);
    return 0;
}
