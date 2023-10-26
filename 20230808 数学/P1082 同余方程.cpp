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

ll exgcd(ll a, ll b, ll &x, ll &y, ll d = 0)
{
    if (b == 0) x = 1, y = 0, d = a;
    else d = exgcd(b, a % b, y, x), y -= a / b * x;
    return d;
}

int main()
{
    ll a = rr, b = rr;
    ll x = 0, y = 0;

    exgcd(a, b, x, y);
    printf("%lld", (x % b + b) % b);
    return 0;
}
