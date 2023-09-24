#include <bits/stdc++.h>

#define rr read()

using namespace std;

typedef long long ll;

const int N = 35620;

const ll MOD1 = 999911659;
const ll MOD2 = 999911658;

const ll m[4] = {2, 3, 4679, 35617};
const ll r[4] = {499955829, 333303886, 289138806, 877424796};

vector<int> dv;
ll MOD, fr[N], sv[N];

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

ll qpow(ll a, ll b, const ll &p)
{
    ll r = 1;
    for (; b; b >>= 1)
        b & 1 ? (r = r * a % p, a = a * a % p) : a = a * a % p;
    return r;
}

ll comb(int a, int b)
{
    return a < b ? 0 : fr[a] * sv[b] % MOD * sv[a - b] % MOD;
}

ll lucas(int a, int b)
{
    ll r = 1;
    while (a && b)
        r = r * comb(a % MOD, b % MOD) % MOD, a /= MOD, b /= MOD;
    return r;
}

int main()
{
    int n = rr, g = rr;
    if (g % MOD1 == 0)
        printf("0\n"), exit(0);

    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i != 0)
            continue;
        dv.push_back(i);
        if (i * i != n)
            dv.push_back(n / i);
    }

    ll x = 0;
    for (int i = 0; i < 4; ++i)
    {
        MOD = m[i];

        fr[0] = 1;
        for (int j = 1; j < MOD; ++j)
            fr[j] = fr[j - 1] * j % MOD;
        sv[MOD - 1] = qpow(fr[MOD - 1], MOD - 2, MOD);
        for (int j = MOD - 1; j; --j)
            sv[j - 1] = sv[j] * j % MOD;

        for (int j : dv)
            x = (x + lucas(n, j) * r[i] % MOD2) % MOD2;
    }

    ll r = qpow(g, x, MOD1);
    printf("%lld\n", r);
    return 0;
}
