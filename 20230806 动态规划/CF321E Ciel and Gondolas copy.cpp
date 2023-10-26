// LUOGU_RID: 126694629
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ur uread()
inline unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

#define max _max
#define min _min
template<typename _Tp> inline _Tp _max(const _Tp a, const _Tp b) { return a > b ? a : b; }
template<typename _Tp> inline _Tp _min(const _Tp a, const _Tp b) { return a < b ? a : b; }

const int N = 4010;
const int M = 810;

int s[N][N];
int f[N][M];

inline int cost(const int x, const int y) { return (s[y][y] - s[y][x - 1] - s[x - 1][y] + s[x - 1][x - 1]) >> 1; }

signed main() {
    int n = ur, k = ur;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) s[i][j] = ur + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    memset(f, 0x3f, sizeof f); for (int i = 0; i <= n; ++i) f[i][0] = 0;
    for (int i = 1; i <= k; ++i) for (int j = 0; j <= n; ++j) {
        for (int t = 0; t <= j; ++t) f[i][j] = min(f[i][j], f[i - 1][t] + cost(t + 1, j));
    } printf("%d\n", f[k][n]);
    return 0;
}
