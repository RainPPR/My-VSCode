#include <bits/stdc++.h>

#define rr read()

using namespace std;

constexpr int N = 2e5 + 10, M = 2 * N;

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

int h[N], e[M], ne[M], idx;

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

int cir[N], cc;
int st[N], top;
int fvis[N];

int vis[N];
int sz[N];

bool fcir(int u, int fa)
{
    fvis[u] = 1;
    st[++top] = u;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        if (fvis[v])
        {
            cir[++cc] = v, vis[v] = 1;
            for (int k = top; k && st[k] != v; --k)
                cir[++cc] = st[k], vis[st[k]] = 1;
            return true;
        }

        if (fcir(v, u))
            return true;
    }

    --top;
    return false;
}

void dfs(int u)
{
    vis[u] = 1, sz[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (vis[v])
            continue;
        dfs(v);
        sz[u] += sz[v];
    }
}

int main()
{
    int T = rr;
    while (T--)
    {
        top = cc = 0;
        memset(h, -1, sizeof h);
        memset(fvis, 0, sizeof fvis);
        memset(vis, 0, sizeof vis);

        int n = rr;
        for (int i = 0; i < n; ++i)
        {
            int u = rr, v = rr;
            add(u, v), add(v, u);
        }

        fcir(1, -1);

        long long res = 1ll * n * (n - 1);

        for (int i = 1; i <= cc; ++i)
        {
            dfs(cir[i]);
            res -= (1ll * sz[cir[i]] * (sz[cir[i]] - 1)) >> 1;
        }

        printf("%lld\n", res);
    }
    return 0;
}