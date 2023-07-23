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
        while (st < ed && Gy(q[st + 1], q[st]) <= (s + t[i]) * Gx(q[st + 1], q[st]))
            st++;

        dp[i] = Gv(q[st], i);

        while (st < ed && Gy(i, q[ed]) * Gx(q[ed], q[ed - 1]) <= Gy(q[ed], q[ed - 1]) * Gx(i, q[ed]))
            ed--;
        q[++ed] = i;
    }

    printf("%lld\n", dp[n]);
    return 0;
}