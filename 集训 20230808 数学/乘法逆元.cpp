#include <bits/stdc++.h>

#define int long long

using namespace std;

// ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// pow
int quick_pow(int a, int b, const int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % p;
        b >>= 1, a = (a * a) % p;
    }
    return res;
}

// s1: exgcd
int inv1(int a, const int p)
{
    int x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

// s2: pow
int inv2(int a, const int p)
{
    return quick_pow(a, p - 2, p);
}

int main()
{
    return 0;
}