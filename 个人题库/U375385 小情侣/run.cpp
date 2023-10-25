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

const int N = 2e6 + 10;

int a[N], b[N]; ll s[N];

int main() {
    int n = rr, m = rr, p = rr;
    for (int i = 1; i <= n; ++i) a[i] = rr;
    for (int i = 1; i <= m; ++i) b[i] = rr;
    sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + m);
    for (int i = 1; i <= m; ++i) s[i] = s[i - 1] + b[i];
    ll ans = 0; for (int i = 1, j = m; i <= n; ++i) {
        while (j && b[j] >= p - a[i]) --j;
        ans += 1ll * a[i] * j + s[j] + 1ll * p * (m - j);
    } printf("%lld\n", ans);
    return 0;
}
