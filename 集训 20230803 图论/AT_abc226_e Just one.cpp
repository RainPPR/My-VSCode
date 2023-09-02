#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 4e5 + 10;
const int MOD = 998244353;

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

int h[N], e[M], ne[M], idx;

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

int cntn, cntm;
int vis[N];

void dfs(int u)
{
    ++cntn, vis[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        ++cntm;
        if (vis[v])
            continue;
        dfs(v);
    }
}

int main()
{
    memset(h, -1, sizeof h);

    n = read(), m = read();

    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        u = read(), v = read();
        add(u, v), add(v, u);
    }

    int res = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;

        cntn = cntm = 0;
        dfs(i);

        if (cntn != (cntm >> 1))
            printf("0\n"), exit(0);
        res = (res << 1) % MOD;
    }

    printf("%d\n", res);
    return 0;
}