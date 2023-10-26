#include <bits/stdc++.h>

#define rr read()

using namespace std;

typedef long long ll;

inline ll read()
{
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

ll qpow(ll a, ll b, const ll p, ll r = 1)
{
    for (; b; b >>= 1)
        b & 1 ? r = r * a % p, a = a *a % p : a = a * a % p;
    return r;
}

ll comb(ll a, ll b, const ll p, ll r = 1)
{
    for (int i = a, j = 1; j <= b; --i, ++j)
        r = r * i % p * qpow(j, p - 2, p) % p;
    return r;
}

int lucas(ll a, ll b, const ll p, ll r = 1)
{
    while (a >= p || b >= p)
        r = r * comb(a % p, b % p, p) % p, a /= p, b /= p;
    return r * comb(a, b, p) % p;
}

int main()
{
    ll t = rr, a, b, p;
    while (t--)
        a = rr, b = rr, p = rr, printf("%lld\n", lucas(a, b, p));
    return 0;
}
