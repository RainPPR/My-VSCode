#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 1e5 + 10;
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

int a[N], pos[N];
long long fr[N];

long long qp(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return res;
}

inline long long ny(long long q)
{
    return qp(q, MOD - 2);
}

inline long long comb(int s, int t)
{
    return t > s ? 0 : fr[s] * ny(fr[t] * fr[s - t] % MOD) % MOD;
}

inline long long calc(int n, int m, int k)
{
    return (comb(n, k) - comb(m, k - 1) + MOD) % MOD;
}

int main()
{
    fr[0] = 1;

    int n = rr + 1, m = 0;
    for (int i = 1; i <= n; ++i)
        fr[i] = 1ll * i * fr[i - 1] % MOD;

    for (int i = 1; i <= n; ++i)
    {
        int x = rr;
        if (pos[x])
            m = n - i + pos[x] - 1;
        pos[x] = i;
    }

    for (int k = 1; k <= n; ++k)
        printf("%lld\n", calc(n, m, k));
    return 0;
}
