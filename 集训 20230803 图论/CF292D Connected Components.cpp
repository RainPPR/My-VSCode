#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 510;
const int M = 1e4 + 10;

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

struct dsu
{
    int f[N];
    int cnt;

    void init(int n)
    {
        cnt = n;
        for (int i = 1; i <= n; ++i)
            f[i] = i;
    }

    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    void merge(int x, int y) { x = find(x), y = find(y), f[x] = y, cnt -= x != y; }
} nul, l[M], r[M];

dsu merge(dsu a, dsu &b)
{
    for (int i = 1; i <= n; ++i)
        if (i != b.f[i])
            a.merge(i, b.find(i));
    return a;
}

struct
{
    int a, b;
} q[M];

int main()
{
    n = rr, m = rr;
    nul.init(n);

    for (int i = 1; i <= m; ++i)
        q[i] = {rr, rr}, l[i] = r[i] = nul;

    l[0] = r[m + 1] = nul;
    for (int i = 1; i <= m; ++i)
        l[i] = l[i - 1], l[i].merge(q[i].a, q[i].b);
    for (int i = m; i >= 1; --i)
        r[i] = r[i + 1], r[i].merge(q[i].a, q[i].b);

    int k = rr;
    while (k--)
    {
        int a = rr, b = rr;
        printf("%d\n", merge(l[a - 1], r[b + 1]).cnt);
    }

    return 0;
}