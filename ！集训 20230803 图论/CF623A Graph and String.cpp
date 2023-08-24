#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int M = N * (N - 1) / 2;

const char res[3] = {'b', 'a', 'c'};

inline int read()
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
int color[N];

int c[N];
int g[N][N];

bool dfs(int u, int c)
{
    color[u] = c;
    for (int v = 1; v <= n; ++v)
    {
        if (!g[u][v])
            continue;
        if (color[v] == c)
            return false;
        else if (!color[v] && !dfs(v, 3 - c))
            return false;
    }
    return true;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = (i != j);
    for (int i = 1; i <= m; ++i)
    {
        int u = read(), v = read();
        ++c[u], ++c[v];
        g[u][v] = 0, g[v][u] = 0;
    }

    for (int i = 1; i <= n; ++i)
        if (c[i] != n - 1 && !color[i] && !dfs(i, 1))
            printf("No\n"), exit(0);

    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (!g[i][j] && color[i] * color[j] == 2)
                printf("No\n"), exit(0);

    printf("Yes\n");
    for (int i = 1; i <= n; ++i)
        putchar(res[color[i]]);
    putchar('\n');

    return 0;
}