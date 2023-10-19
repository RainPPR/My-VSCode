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

const int N = 5e4 + 10;
const ll MOD = 998244353;

char str[N];

inline bool c2(const int a, const int b) {
    return a < b;
} inline bool c3(const int a, const int b) {
    return a > b;
}

signed main() {
    int n = rr(int), m = rr(int), k = rr(int);
    scanf("%s", str);
    while (m--) {
        int op = rr(int), a = rr(int) - 1, b = rr(int);
        if (op == 1) {
            str[a] = b + '0';
        } else if (op == 2) {
            sort(str + a, str + b, c2);
        } else if (op == 3) {
            sort(str + a, str + b, c3);
        } else {
            ll res = 0; for (int i = a; i < b; ++i) res = (res * k % MOD + str[i] - '0') % MOD;
            printf("%lld\n", res);
        }
    } return 0;
}
