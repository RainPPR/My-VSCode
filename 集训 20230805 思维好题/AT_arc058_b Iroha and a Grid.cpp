#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

long long fact[N], infact[N];

inline long long qpow(long long a, long long b)
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

inline long long comb(const int &n, const int &m)
{
    if (n < m)
        return 0;
    return 1ll * fact[n] * infact[m] % MOD * infact[n - m] % MOD;
}

inline long long calc(const int &h, const int &w)
{
    return comb(h + w - 2, h - 1);
}

int main()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % MOD, infact[i] = infact[i - 1] * qpow(i, MOD - 2) % MOD;

    int h = rr, w = rr, a = rr, b = rr;

    long long res = 0;
    for (int i = b + 1; i <= w; ++i)
        res = (res + calc(h - a, i) * calc(a, w - i + 1) % MOD) % MOD;

    printf("%lld\n", res);
    return 0;
}
