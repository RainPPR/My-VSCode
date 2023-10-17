#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline ll read() {
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

signed main() {
    int n = rr, m = rr; ll k = rr;
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= n; ++i) res1 += rr & 1;
    for (int i = 1; i <= m; ++i) rr, rr, res2 += (rr & 1) ^ 1;
    printf("%d %d\n", res1, res2);
    return 0;
}
