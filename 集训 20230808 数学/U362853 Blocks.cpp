#include <bits/stdc++.h>

#define ur uread()

using namespace std;

const int MOD = 1e4 + 7;

inline unsigned uread()
{
    unsigned num = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

// dp[k][0] oo
// dp[k][1] jo
// dp[k][2] jj

// dp[i][0] = 2 * dp[i - 1][0] + 1 * dp[i - 1][1]   0
// dp[i][1] = 2 * dp[i - 1][0] + 2 * dp[i - 1][1] + 2 * dp[i - 1][2]
// dp[i][2] = 0                  1 * dp[i - 1][1] + 2 * dp[i - 1][2]

//        | 2 1 0 |
// Base = | 2 2 2 |
//        | 0 1 2 |

// dp[0] = {1, 0, 0}
// dp[n] = dp[0] * Base ^ n

struct matrix {
    int a[3][3];
    matrix operator *(const matrix &t) const {
        matrix r;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            r.a[i][j] = 0; for (int k = 0; k < 3; ++k)
                r.a[i][j] = (r.a[i][j] + a[i][k] * t.a[k][j]) % MOD; }
        return r;
    }
};

void solve(int n)
{
    matrix base = {{2, 1, 0, 2, 2, 2, 0, 1, 2}};
    matrix res = {{1, 0, 0, 0, 1, 0, 0, 0, 1}};
    for (; n; n >>= 1) {
        if (n & 1) res = res * base;
        base = base * base;
    }
    printf("%d\n", res.a[0][0]);
}

int main()
{
    int T = ur;
    while (T--) solve(ur);
    return 0;
}
