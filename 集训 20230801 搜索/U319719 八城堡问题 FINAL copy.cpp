#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int M = (1 << 20) + 1;

int n, m;
int a[N];

int n2, ans;
int g[M];
int f[N][M];

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

int main()
{
    for (int i = 1; i < M; ++i)
        g[i] = g[i & (i - 1)] + 1;

    scanf("%d%d", &n, &m);
    while (n && m)
    {
        memset(f, 0, sizeof f);
        ans = 0;

        char line[N];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", line);
            for (int j = 1; j <= n; ++j)
                a[i] = a[i] << 1 | (line[j - 1] == 'H');
        }

        n2 = n >> 1;
        dfs1(1, 0);
        dfs2(n2 + 1, 0);

        printf("%d\n", ans);
        scanf("%d%d", &n, &m);
    }
    return 0;
}
