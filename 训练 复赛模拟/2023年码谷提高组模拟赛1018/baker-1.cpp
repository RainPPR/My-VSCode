// ±©Ëã£¬Ô¤ÆÚ 30pts

#include <bits/stdc++.h>

using namespace std;

#define rr(x) read<x>()
template<typename _tp>
inline _tp read() {
    _tp num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

int main() {
    int n = rr(int), m = rr(int);
    long long cnt = 0;
    for (int s = 3; s <= n + n + n; ++s)
        for (int i = 1; i <= n; ++i)
            for (int j = max(s - i - n, 1); j <= min(s - i - 1, n); ++j)
                if (++cnt == m) printf("%d %d %d\n", i, j, s - i - j), exit(0);
    return 0;
}
