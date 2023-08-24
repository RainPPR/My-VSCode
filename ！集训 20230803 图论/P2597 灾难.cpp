#include <bits/stdc++.h>

using namespace std;

const int N = 65536;
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
int in[N];

vector<int> g[N];
vector<int> rg[N];

vector<int> top;

void topsort()
{
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int u = q.front();
        top.push_back(u), q.pop();
        for (int v : g[u])
            if (--in[v] == 0)
                q.push(v);
    }
}

int depth[N];
int f[N][K];

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);

    for (int i = 16; i >= 0; --i)
    {
        if (depth[f[x][i]] >= depth[y])
            x = f[x][i];
        if (x == y)
            return x;
    }

    for (int i = 16; i >= 0; --i)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

vector<int> eg[N];

void build()
{
    for (int i = 1; i < top.size(); ++i)
    {
        int u = top[i], fa = rg[u][0];
        for (int j = 1; j < rg[u].size(); ++j)
            fa = lca(fa, rg[u][j]);

        eg[fa].push_back(u);

        depth[u] = depth[fa] + 1;
        f[u][0] = fa;
        for (int i = 0; i < 16; ++i)
            f[u][i + 1] = f[f[u][i]][i];
    }
}

int ans[N];

void dfs(int u)
{
    ans[u] = 1;
    for (int v : eg[u])
        dfs(v), ans[u] += ans[v];
}

int main()
{
    n = read();

    int v;
    for (int i = 1; i <= n; ++i)
    {
        while (v = read())
            g[v].push_back(i), rg[i].push_back(v), ++in[i];
        if (in[i] == 0)
            g[0].push_back(i), rg[i].push_back(0), ++in[i];
    }

    topsort();
    build();
    dfs(0);

    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i] - 1);
    return 0;
}
