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

const int N = 1e5 + 10;

int a[N], f[N];

#define abs(x) _abs(x)
template<typename _t> inline _t _abs(const _t x) { return x < 0 ? -x : x; }

int main() {
    int n = rr(int);
    for (int i = 1; i <= n; ++i) a[i] = rr(int);
    f[1] = 0, f[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; ++i) f[i] = min(f[i - 1] + abs(a[i] - a[i - 1]), f[i - 2] + abs(a[i] - a[i - 2]));
    printf("%d\n", f[n]);
    return 0;
}
