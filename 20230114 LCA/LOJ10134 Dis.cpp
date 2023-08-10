#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int K = 20;

int n, m;
int h[N], w[N], e[N], ne[N], idx;

int depth[N];
int f[N][K], k[N][K];

void add(int u, int v, int x)
{
    w[idx] = x;
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

void init(int u, int fa)
{
    depth[u] = depth[fa] + 1;
    for (int i = 0; i <= n; ++i)
        f[u][i + 1] = f[f[u][i]][i], k[u][i + 1] = k[u][i] + k[f[u][i]][i];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        f[v][0] = u;
        k[v][0] = w[i];
        init(v, u);
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);

    int ans = 0;
    for (int i = n; i >= 0; --i)
    {
        if (depth[f[x][i]] >= depth[y])
            ans += k[x][i], x = f[x][i];
        if (x == y)
            return ans;
    }

    for (int i = n; i >= 0; --i)
    {
        if (f[x][i] != f[y][i])
        {
            ans += k[x][i] + k[y][i];
            x = f[x][i], y = f[y][i];
        }
    }

    if (x != y)
        ans += k[x][0] + k[y][0];
    return ans;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);

    for (int i = 1; i < n; ++i)
    {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        add(u, v, x);
        add(v, u, x);
    }

    n = log2(n);
    init(1, 0);

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}