#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int M = (1 << 20) + 1;

int n, m;
int a[N];

int g[M];

namespace s1
{
    int ans;

    void dfs(int k, int now)
    {
        if (g[now] > m)
            return;
        if (k > n)
        {
            if (g[now] == m)
                ++ans;
            return;
        }

        dfs(k + 1, now);
        for (int i = 1; i <= n; ++i)
        {
            int t = 1 << (n - i);
            if ((a[k] & t) && (now & t) == 0)
                dfs(k + 1, now | t);
        }
    }

    int solve()
    {
        ans = 0;
        dfs(1, 0);
        return ans;
    }
}

namespace s2
{
    int n2;
    int f[N][M];

    int ans;

    void dfs1(int k, int now)
    {
        if (g[now] > m)
            return;
        if (k > n2)
        {
            int r = now ^ ((1 << n) - 1);
            if (g[now] == m)
                ++f[m][0];
            for (int t = r; t; t = (t - 1) & r)
                ++f[g[now]][t];
            return;
        }

        dfs1(k + 1, now);
        for (int i = 1; i <= n; ++i)
        {
            int t = 1 << (n - i);
            if ((a[k] & t) && (now & t) == 0)
                dfs1(k + 1, now | t);
        }
    }

    void dfs2(int k, int now)
    {
        if (g[now] > m)
            return;
        if (k > n)
        {
            ans += f[m - g[now]][now];
            return;
        }

        dfs2(k + 1, now);
        for (int i = 1; i <= n; ++i)
        {
            int t = 1 << (n - i);
            if ((a[k] & t) && (now & t) == 0)
                dfs2(k + 1, now | t);
        }
    }

    int solve()
    {
        memset(f, 0, sizeof f);

        n2 = n >> 1;
        dfs1(1, 0);

        ans = 0;
        dfs2(n2 + 1, 0);

        return ans;
    }
}

namespace s3
{
    int mem[N][M];

    int dfs(int k, int now)
    {
        if (g[now] > m)
            return 0;
        if (k > n)
        {
            if (g[now] == m)
                return 1;
            return 0;
        }

        if (mem[k][now] != -1)
            return mem[k][now];

        int res = dfs(k + 1, now);
        for (int i = 1; i <= n; ++i)
        {
            int t = 1 << (n - i);
            if ((a[k] & t) && (now & t) == 0)
                res += dfs(k + 1, now | t);
        }

        return mem[k][now] = res;
    }

    int solve()
    {
        memset(mem, -1, sizeof mem);
        return dfs(1, 0);
    }
}

namespace s4
{
    int dp[N][M];

    int solve()
    {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < (1 << n); ++i)
            if (g[i] == m)
                dp[n + 1][i] = 1;

        for (int i = n; i >= 2; --i)
        {
            for (int j = 0; j < (1 << n); ++j)
            {
                if (g[j] > m)
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = dp[i + 1][j];
                    for (int r = 1; r <= n; ++r)
                    {
                        int t = 1 << (n - r);
                        if ((a[i] & t) && (j & t) == 0)
                            dp[i][j] += dp[i + 1][j | t];
                    }
                }
            }
        }

        int res = dp[2][0];
        for (int r = 1; r <= n; ++r)
        {
            int t = 1 << (n - r);
            if (a[1] & t)
                res += dp[2][t];
        }
        return res;
    }
}

namespace s5
{
    int dp[M];

    int solve()
    {
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
        return res;
    }
}

int main()
{
    for (int i = 1; i < M; ++i)
        g[i] = g[i & (i - 1)] + 1;

    scanf("%d%d", &n, &m);
    while (n && m)
    {
        char line[N];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", line);
            for (int j = 1; j <= n; ++j)
                a[i] = a[i] << 1 | (line[j - 1] == 'H');
        }

        printf("%d\n", s5::solve());

        scanf("%d%d", &n, &m);
    }
    return 0;
}