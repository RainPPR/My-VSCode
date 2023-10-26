#include <bits/stdc++.h>

#define rr read()

using namespace std;

typedef long long ll;

const int N = 10;

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

ll exgcd(ll a, ll b, ll &x, ll &y, ll d = 0)
{
    if (b == 0)
        x = 1, y = 0, d = a;
    else
        d = exgcd(b, a % b, y, x), y -= a / b * x;
    return d;
}

ll inv(ll a, const ll m, ll x = 0, ll y = 0)
{
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

int a[N], m[N];

int main()
{
    int n = rr;

    ll mul = 1;
    for (int i = 1; i <= n; ++i)
        m[i] = rr, a[i] = rr, mul *= m[i];

    ll x = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll t = mul / m[i], c = inv(t, m[i]);
        x = (x + a[i] * t % mul * c % mul) % mul;
    }

    printf("%lld\n", x);
    return 0;
}
