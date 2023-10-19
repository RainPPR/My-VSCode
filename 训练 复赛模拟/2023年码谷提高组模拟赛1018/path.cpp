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

const int MOD = 1e9 + 7;
const int MAXN = 110;
const int MAXD = 110;

int n, k, d;

ll mem[MAXD][MAXN * MAXD][2];
ll f(int pos, int sum, bool gre) {
    if (~mem[pos][sum][gre]) return mem[pos][sum][gre];
    if (sum > n) return 0;
    else if (sum == n) return 1 & gre;
    else if (!pos) return 0;
    ll res = 0;
    for (int i = 1; i <= k; ++i)
        res = (res + f(pos - 1, sum + i, gre | (i >= d))) % MOD;
    return mem[pos][sum][gre] = res;
}

int main() {
    memset(mem, -1, sizeof mem);
    n = rr(int), k = rr(int), d = rr(int);
    printf("%lld\n", f(n, 0, 0));
    return 0;
}
