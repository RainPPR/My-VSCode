#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max _max
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int N = 1e5 + 10;

int n, a[N];
int l[N], s[N], r[N];

map<int, int> cnt;

signed main() {
    // freopen("in.txt", "r", stdin);
    int T = rr; while (T--) {
        n = rr; for (int i = 1; i <= n; ++i) a[i] = rr;
        cnt.clear(); for (int i = 1; i <= n; ++i) if (++cnt[a[i]] == 1) l[i] = 1; else l[i] = 0;
        cnt.clear(); for (int i = n; i >= 1; --i) if (++cnt[a[i]] == 1) r[i] = 1; else r[i] = 0;
        for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + l[i];
        ll res = 0; for (int i = 1; i <= n; ++i) res += 1ll * s[i] * r[i];
        printf("%lld\n", res);
    } return 0;
}
