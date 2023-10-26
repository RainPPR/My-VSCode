#include <bits/stdc++.h>

#define rr read()

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

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

ll s[N], sv[N];
ll inv[N];

ll qpow(ll a, ll b, const ll p, ll r = 1)
{
    for (; b; b >>= 1)
        b & 1 ? r = r * a % p, a = a * a % p : a = a * a % p;
    return r;
}

int main()
{
    s[0] = 1;
    for (int i = 1; i < N; ++i)
        s[i] = s[i - 1] * i % MOD;

    sv[N - 1] = qpow(s[N - 1], MOD - 2, MOD);
    for (int i = N - 1; i >= 1; --i)
        sv[i - 1] = sv[i] * i % MOD;

    inv[0] = 1;
    for (int i = 1; i < N; ++i)
        inv[i] = sv[i] * s[i - 1] % MOD;

    int t = rr, a, b;
    while (t--)
        a = rr, b = rr, printf("%lld\n", s[a] * inv[b] % MOD * inv[a - b] % MOD);
    return 0;
}
