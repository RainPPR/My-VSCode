#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 1e6 + 10;
const int MOD = 998244353;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

int n, s[N];

struct edge
{
    int u, v;
};

vector<edge> g;

int f[N], sz[N];

inline int find(const int &x)
{
    return x == f[x] ? x : find(f[x]);
}

long long res;

void dfs(const int &now, const long long &val, const int &k)
{
    if (now == n - 1)
    {
        res = (res + val) % MOD;
        return;
    }

    for (int i = k; i < g.size(); ++i)
    {
        int a = find(g[i].u), b = find(g[i].v);
        if (a == b)
            continue;

        if (sz[b] > sz[a])
            swap(a, b);
        f[b] = a;
        sz[a] += sz[b];

        dfs(now + 1, val + (s[g[i].u] ^ s[g[i].v]), i + 1);

        f[b] = b;
        sz[a] -= sz[b];
    }
}

int main()
{
    n = rr;
    s[1] = rr, f[1] = 1;

    bool ist1 = true;
    for (int i = 2; i <= n; ++i)
    {
        s[i] = rr, f[i] = i;
        if (s[i] != s[i - 1])
            ist1 = false;
    }

    if (ist1)
        printf("0\n");
    else
    {
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                g.push_back({i, j});

        dfs(0, 0, 0);
        printf("%d\n", res);
    }

    return 0;
}
