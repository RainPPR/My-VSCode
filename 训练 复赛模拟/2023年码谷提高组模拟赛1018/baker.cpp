#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr(x) read<x>()
template<typename _tp>
inline _tp read() {
    _tp num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define f(t) ((s - t > n) ? (n + n + 1 - (s - t)) : (s - t - 1))
ll g(int s, int n) {
    int a = max(s - n - n, 1), b = max({s - n - n, 1, min(n + 1, s - max(1, n))}), c = min(n, s - 2);
    ll res = ll(1) * (n + n + 1 - s) * (b - a) + ll(1) * (s - 1) * (c - b + 1);
    res += ll(1) * (a + b - 1) * (b - a) / 2;
    res -= ll(1) * (b + c) * (c - b + 1) / 2;
    return res;
}

int main() {
    int n = rr(int); ll m = rr(ll);
    ll cnt = 0; int s, i, j, k;
    s = 3; while (s <= n + n + n) {
        ll t = cnt + g(s, n);
        if (t >= m) break;
        else cnt = t, ++s;
    } i = max(s - n - n, 1);
    while (i <= min(n, s - 2)) {
        ll t = cnt + f(i);
        if (t >= m) break;
        else cnt = t, ++i;
    } for (j = max(s - i - n, 1); j <= min(s - i - 1, n); ++j)
        if (++cnt == m) printf("%d %d %d\n", i, j, s - i - j), exit(0);
    return 0;
}
