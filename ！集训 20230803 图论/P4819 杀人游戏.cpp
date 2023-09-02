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

void add(const _g &t)
{
    add(t.u, t.v);
}

int low[N], dfn[N];

int cnt, k;
int vis[N], grp[N];

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
        v = s.top(), vis[v] = 0, grp[v] = cnt;
        s.pop();
    } while (u != v);
}

void write(int a, int b)
{
    printf("%.6lf", double(a) / b);
}

int in[N];

int main()
{
    memset(h, -1, sizeof h);

    n = rr, m = rr;
    for (int i = 1; i <= m; ++i)
        add(g[i] = {rr, rr});

    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= m; ++i)
        if (grp[g[i].v] != grp[g[i].u])
            ++in[grp[g[i].v]];

    int res = 0;
    for (int i = 1; i <= cnt; ++i)
        res += in[i] == 0;

    if (res == n)
        --res;
    cerr << res << " in " << n << endl;
    write(n - res, n);

    return 0;
}