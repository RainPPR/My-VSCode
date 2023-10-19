#include <bits/stdc++.h>

using namespace std;

#define rr(tp) read<tp>()
template<typename tp> inline tp read() {
    tp num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define min(a, b) _min(a, b)
template<typename tp> inline tp _min(const tp a, const tp b) { return a < b ? a : b; }
#define max(a, b) _max(a, b)
template<typename tp> inline tp _max(const tp a, const tp b) { return a > b ? a : b; }

const int N = 1e5 + 10;

int n, m, w;
int h[N], c[N];

bool check(const int mid) {
    for (int i = 1; i <= n; ++i) c[i] = h[i] - h[i - 1];
    int now = 0, res = 0; for (int i = 1; i <= n; ++i) {
        now += c[i]; if (now >= mid) continue;
        int nd = mid - now;
        res += nd, c[i] += nd, now += nd;
        if (res > m) return false;
        if (i + w <= n) c[i + w] -= nd;
    } return true;
}

signed main() {
    n = rr(int), m = rr(int), w = rr(int);
    int l, r; for (int i = 1; i <= n; ++i) {
        h[i] = rr(int);
        l = min(l, h[i]), r = max(r, h[i]);
    } r += m + 1; while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    } printf("%d\n", l);
    return 0;
}
