#include <bits/stdc++.h>

using namespace std;

long long MOD;

struct matrix
{
    long long a[3][3];
    matrix operator*(const matrix &t) const
    {
        matrix res;
        memset(res.a, 0, sizeof res.a);
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= 2; ++j)
                for (int k = 1; k <= 2; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * t.a[k][j] % MOD) % MOD;
        return res;
    }
};

int main()
{
    long long p, q, a1, a2, n;
    cin >> p >> q >> a1 >> a2 >> n >> MOD;

    if (n == 1)
        printf("%lld\n", a1), exit(0);
    else if (n == 2)
        printf("%lld\n", a2), exit(0);

    matrix a = {{{0, 0, 0},
                 {0, p, 1},
                 {0, q, 0}}};
    matrix res = {{{0, 0, 0},
                   {0, 1, 0},
                   {0, 0, 1}}};

    long long k = n - 2;
    while (k)
    {
        if (k & 1)
            res = res * a;
        k >>= 1, a = a * a;
    }

    long long ans = (a2 * res.a[1][1] % MOD + a1 * res.a[2][1] % MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}
