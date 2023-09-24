#include <bits/stdc++.h>

#define int long long
#define rr read()

using namespace std;

const int N = 110;
const int MOD = 1e9 + 7;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

struct matrix
{
    int n, m, a[N][N];

    matrix() { memset(a, 0, sizeof a); }
    matrix(int _n, int _m) { n = _n, m = _m, memset(a, 0, sizeof a); }

    matrix(int _n)
    {
        n = m = _n;
        for (int i = 1; i <= n; ++i)
            a[i][i] = 1;
    }

    matrix(int _n, int _m, const int t[N][N])
    {
        n = _n, m = _m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                a[i][j] = t[i][j];
    }

    matrix operator*(const matrix &b) const
    {
        matrix res;
        res.n = n, res.m = b.m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= b.m; ++j)
                for (int k = 1; k <= m; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j] % MOD) % MOD;
        return res;
    }
};

matrix pow(const int &n, matrix a, int k)
{
    matrix res(n);
    while (k)
    {
        if (k & 1)
            res = res * a;
        k >>= 1, a = a * a;
    }
    return res;
}

signed main()
{
    int n = rr, k = rr;

    matrix a(n, n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a.a[i][j] = rr;

    matrix res = pow(n, a, k);
    for (int i = 1; i <= n; ++i, putchar('\n'))
        for (int j = 1; j <= n; ++j)
            printf("%lld ", res.a[i][j]);

    return 0;
}
