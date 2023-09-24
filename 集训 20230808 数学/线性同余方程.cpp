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

// ax = 1 (mod b)
int lieu1(int a, int b)
{
    int x, y;
    int d = exgcd(a, b, x, y);
    if (d != 1)
        return -1;
    return (x % b + b) % b;
}

// ax = n (mod b)
int lieu(int a, int b, int n)
{
    int x, y;
    int d = exgcd(a, b, x, y);
    if (n % d != 0)
        return -1;
    int t = b / d;
    return (x % t + t) % t;
}

int main()
{
    return 0;
}