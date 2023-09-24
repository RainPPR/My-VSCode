#include <bits/stdc++.h>

#define rr read()

using namespace std;

typedef long long ll;

const int N = 3e6 + 10;

inline ll read()
{
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (num == -1)
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

ll s[N], sv[N];

ll qpow(ll a, ll b, const ll p, ll r = 1)
{
    for (; b; b >>= 1)
        b & 1 ? r = r * a % p, a = a * a % p : a = a * a % p;
    return r;
}

int main()
{
    const int n = rr;
    const ll p = rr;

    s[0] = 1;
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] * i % p;

    sv[n] = qpow(s[n], p - 2, p);
    for (int i = n; i; --i)
        sv[i - 1] = sv[i] * i % p;

    for (int i = 1; i <= n; ++i)
        printf("%lld\n", sv[i] * s[i - 1] % p);
    return 0;
}
