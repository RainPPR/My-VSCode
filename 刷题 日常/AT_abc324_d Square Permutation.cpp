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

const int mn = sqrt(1e14 - 1);

int base[10], tong[10];

int main() {
    int n = rr(int), k = 0, res = 0; ll b = rr(ll), t = b;
    while (t) ++base[t % 10], t /= 10, ++k;
    base[0] += n - k; for (int i = 0; i < mn; ++i) {
        t = 1ll * i * i, k = 0;
        for (int i = 0; i < 10; ++i) tong[i] = 0;
        while (t) ++tong[t % 10], t /= 10, ++k;
        if (k > n) break; if (base[0] < tong[0]) continue;
        bool flag = true; for (int i = 1; i < 10; ++i) {
            if (base[i] != tong[i]) { flag = false; break; }
        } res += flag;
    } printf("%d\n", res);
    return 0;
}
