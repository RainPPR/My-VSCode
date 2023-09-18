#include <bits/stdc++.h>

#define rr read()

using namespace std;

const long long MOD = 1e9 + 7;

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
    long long a[4][4];
    matrix operator*(const matrix &t) const
    {
        matrix res;
        memset(res.a, 0, sizeof res.a);
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= 3; ++j)
                for (int k = 1; k <= 3; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * t.a[k][j] % MOD) % MOD;
        return res;
    }
};

int main()
{
    int T = rr;
    while (T--)
    {
        int n = rr;

        if (n <= 3)
        {
            printf("1\n");
            continue;
        }

        matrix Base = {{{0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 1},
                        {0, 1, 0, 0}}};
        matrix res = {{{0, 0, 0, 0},
                       {0, 1, 0, 0},
                       {0, 0, 1, 0},
                       {0, 0, 0, 1}}};

        int k = n - 3;
        while (k)
        {
            if (k & 1)
                res = res * Base;
            k >>= 1, Base = Base * Base;
        }

        printf("%lld\n", (res.a[1][1] + res.a[2][1] + res.a[3][1]) % MOD);
    }

    return 0;
}
