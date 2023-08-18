#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int M = (1 << 20) + 1;

int n, m;
int a[N];

int g[M];
int dp[M];

int read()
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

int main()
{
    for (int i = 1; i < M; ++i)
        g[i] = g[i & (i - 1)] + 1;

    n = read(), m = read();
    while (n)
    {
        char line[N];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", line);
            for (int j = 1; j <= n; ++j)
                a[i] = a[i] << 1 | (line[j - 1] == 'H');
        }

        memset(dp, 0, sizeof dp);
        for (int i = 0; i < (1 << n); ++i)
            if (g[i] == m)
                dp[i] = 1;

        for (int i = n; i >= 2; --i)
        {
            for (int j = 0; j < (1 << n); ++j)
            {
                if (g[j] > m)
                    continue;
                for (int r = 1; r <= n; ++r)
                {
                    int t = 1 << (n - r);
                    if ((a[i] & t) && (j & t) == 0 && (j | t) != j)
                        dp[j] += dp[j | t];
                }
            }
        }

        int res = dp[0];
        for (int r = 1; r <= n; ++r)
        {
            int t = 1 << (n - r);
            if (a[1] & t)
                res += dp[t];
        }

        printf("%d\n", res);
        n = read(), m = read();
    }
    return 0;
}