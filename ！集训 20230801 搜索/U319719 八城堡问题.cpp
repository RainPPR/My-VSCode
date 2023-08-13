#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int M = (1 << 20) + 1;

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
            int r = now ^ (1 << n) - 1;
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

int main()
{
    for (int i = 0; i < M; ++i)
    {
        int t = i;
        while (t)
        {
            if (t & 1)
                ++g[i];
            t >>= 1;
        }
    }

    n = read(), m = read();
    while (n && m)
    {
        char line[N];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", line);
            for (int j = 1; j <= n; ++j)
                a[i] = a[i] << 1 | (line[j - 1] == 'H');
        }

        printf("%d\n", s3::solve());

        n = read(), m = read();
    }
    return 0;
}