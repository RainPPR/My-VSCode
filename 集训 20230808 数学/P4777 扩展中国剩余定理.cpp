#include <bits/stdc++.h>

#define rr read()

using namespace std;

typedef long long ll;
typedef __int128_t vl;

const int N = 1e5 + 10;

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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll exgcd(ll a, ll b, vl &x, vl &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void merge(ll &a1, ll &m1, ll a2, ll m2)
{
    ll g = gcd(m1, m2), m = m1 / g * m2;

    vl p, q;
    exgcd(m1 / g, m2 / g, p, q);

    p = p * m1 % m;
    p = p * ((a2 - a1) / g) % m;

    a1 = (a1 + p + m) % m;
    m1 = m;
}

int main()
{
    int n = rr;

    ll mm = rr, aa = rr;
    for (int i = 1; i < n; ++i)
    {
        ll m = rr, a = rr;
        merge(aa, mm, a, m);
    }

    printf("%lld\n", aa % mm);
    return 0;
}
