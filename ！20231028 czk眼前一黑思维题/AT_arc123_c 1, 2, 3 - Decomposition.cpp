#include <bits/stdc++.h>

using ll = long long;

#define ri read<int>()
#define rl read<ll>()
template<typename tp> inline tp read() {
    tp num = 0; int flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

std::map<ll, int> mem; int dfs(ll n) {
    if (!n) return 0; if (mem.count(n)) return mem[n];
    ll a = n / 10; int b = n % 10, &f = mem[n];
    if (1 <= b && b <= 3 && dfs(a) <= 1) return f = 1;
    if (2 <= b && b <= 6 && dfs(a) <= 2) return f = 2;
    if (3 <= b && b <= 9 && dfs(a) <= 3) return f = 3;
    if (4 <= b && b <= 9 && dfs(a) <= 4) return f = 4;
    if (0 <= b && b <= 2 && dfs(a - 1) <= 4) return f = 4;
    else return f = 5;
}

signed main() {
    int T = ri; while (T--)
    printf("%d\n", dfs(rl));
    return 0;
}
