#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 2010;
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

long long comb[N][N];

int main()
{
    comb[0][0] = 1;
    for (int i = 1; i < N; ++i)
    {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }

    int t = rr, a, b;
    while (t--)
        a = rr, b = rr, printf("%lld\n", comb[a][b]);
    return 0;
}
