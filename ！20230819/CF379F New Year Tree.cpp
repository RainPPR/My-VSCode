#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 1e6 + 10;
const int K = 20;

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

int n;

int d[N];
int f[N][K];

int lca(int x, int y)
{
    if (d[x] < d[y])
        swap(x, y);

    for (int i = 19; i >= 0; --i)
    {
        if (d[f[x][i]] >= d[y])
            x = f[x][i];
        if (x == y)
            return x;
    }

    for (int i = 19; i >= 0; --i)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main()
{
    n = 4;
    f[2][0] = f[3][0] = f[4][0] = 1;
    d[1] = 1, d[2] = d[3] = d[4] = 2;

    int len = 2, l = 2, r = 3;

    int m = rr;
    while (m--)
    {
        int x = rr;
        int u = n + 1, v = n + 2;

        f[u][0] = f[v][0] = x;
        d[u] = d[v] = d[x] + 1;
        for (int i = 1; i <= 19; ++i)
            f[u][i] = f[v][i] = f[f[u][i - 1]][i - 1];

        n += 2;

        if (d[r] + d[u] - d[lca(r, u)] * 2 > len)
            l = u, ++len;
        else if (d[l] + d[u] - d[lca(l, u)] * 2 > len)
            r = u, ++len;

        printf("%d\n", len);
    }

    return 0;
}
