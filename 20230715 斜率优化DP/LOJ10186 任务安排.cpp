#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e5 + 10;

int n, s;
int t[N], f[N];

int q[N];
int dp[N];

int Gy(int k1, int k2)
{
    return dp[k1] - dp[k2];
}

int Gx(int k1, int k2)
{
    return f[k1] - f[k2];
}

int Gv(int i, int j)
{
    return dp[i] + t[j] * f[j] + s * f[n] - f[i] * (s + t[j]);
}

int find(int l, int r, int st)
{
    if (l == r)
        return l;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (Gy(q[mid + 1], q[mid]) <= (s + t[st]) * Gx(q[mid + 1], q[mid]))
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

signed main()
{
    scanf("%lld %lld", &n, &s);

    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", t + i, f + i);
        t[i] += t[i - 1];
        f[i] += f[i - 1];
    }

    int st = 0, ed = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = Gv(q[find(st, ed, i)], i);
        while (st < ed && Gy(i, q[ed]) * Gx(q[ed], q[ed - 1]) <= Gy(q[ed], q[ed - 1]) * Gx(i, q[ed]))
            ed--;
        q[++ed] = i;
    }

    printf("%lld\n", dp[n]);
    return 0;
}