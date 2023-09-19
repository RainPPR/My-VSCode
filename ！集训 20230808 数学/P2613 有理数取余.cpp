#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 19260817;

inline ll read()
{
    ll num = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0', num %= MOD;
    return num;
}

ll qpow(ll a, ll b, const ll p, ll res = 1)
{
    for (; b; b >>= 1)
        b & 1 ? res = res * a % p, a = a *a % p : a = a * a % p;
    return res;
}

int main()
{
    ll a = read(), b = read();
    if (b == 0)
        printf("Angry!\n"), exit(0);
    ll res = a * qpow(b, MOD - 2, MOD) % MOD;
    printf("%lld\n", res);
    return 0;
}
