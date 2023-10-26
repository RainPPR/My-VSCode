#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 1e5 + 10;
const int M = 6e5 + 10;

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

struct _g
{
    int u, v;
} g[M];

int n, m;
int h[N], e[M], ne[M], idx;

void add(int u, int v)
{
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

void add(_g t)
{
    add(t.u, t.v);
}

int low[N], dfn[N];

int cnt, k;

int vis[N], grp[N];
int ins[N];

struct stk
{
    int arr[N], idx;

    void push(int x)
    {
        arr[++idx] = x;
    }
    void pop()
    {
        --idx;
    }
    int top()
    {
        return arr[idx];
    }
} s;

void tarjan(int u)
{
    dfn[u] = low[u] = ++k;
    vis[u] = 1, s.push(u);

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (!dfn[v])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if (vis[v])
            low[u] = min(low[u], low[v]);
    }

    if (dfn[u] != low[u])
        return;

    ++cnt;

    int v;
    do
    {
        v = s.top(), vis[v] = 0, grp[v] = cnt, ++ins[cnt];
        s.pop();
    } while (u != v);
}

void write(int a, int b)
{
    printf("%.6lf", double(a) / b);
}

int in[N];
int vis2[N];

int uh[N], ue[M], une[M], uidx;

void uadd(int u, int v)
{
    ue[uidx] = v;
    une[uidx] = uh[u];
    uh[u] = uidx++;
}

int res;
int cc[N];

void dfs(int u)
{
    if (in[u] == 0)
        ++res;

    cc[u] = ins[u];
    vis2[u] = true;

    --cnt;
    for (int i = uh[u]; i != -1; i = une[i])
    {
        int v = ue[i];
        if (vis2[v])
            continue;
        in[v] = 1, dfs(v);
        cc[u] += cc[v];
    }
}

int main()
{
    memset(h, -1, sizeof h);
    memset(uh, -1, sizeof uh);

    n = rr, m = rr;
    if (n == 1 && m == 0)
        write(1, 1), exit(0);

    for (int i = 1; i <= m; ++i)
        add(g[i] = {rr, rr});

    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= m; ++i)
        if (grp[g[i].v] != grp[g[i].u])
            ++in[grp[g[i].v]], uadd(grp[g[i].u], grp[g[i].v]);

    int t = cnt, k = 0;

    for (int i = 1; i <= t; ++i)
    {
        if (!in[i])
        {
            dfs(i);
            if (cc[i] == 1)
                k = 1;
        }
    }

    write(n - res + k, n);
    return 0;
}
