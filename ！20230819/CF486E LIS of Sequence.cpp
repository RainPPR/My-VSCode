#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 1e5 + 10;

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

inline int lobit(int x)
{
    return x & -x;
}

inline int MAX(const int &a, const int &b)
{
    return a > b ? a : b;
}

struct fentree
{
    int s[N];

    void upd(int x, int t)
    {
        for (; x < N; x += lobit(x))
            s[x] = max(s[x], t);
    }

    int qry(int x)
    {
        int res = 0;
        for (; x; x -= lobit(x))
            res = max(res, s[x]);
        return res;
    }
} f1, f2;

int a[N];

int l1[N], l2[N];
map<pair<int, int>, int> st;

int main()
{
    int n = rr;
    int len = 0;

    for (int i = 1; i <= n; ++i)
    {
        a[i] = rr;
        l1[i] = f1.qry(a[i]) + 1;
        f1.upd(a[i] + 1, l1[i]);
        len = MAX(len, l1[i]);
    }

    for (int i = n; i >= 1; --i)
    {
        a[i] = -a[i] + N;
        l2[i] = f2.qry(a[i]) + 1;
        f2.upd(a[i] + 1, l2[i]);
        ++st[make_pair(l1[i], l2[i])];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (l1[i] + l2[i] < len + 1)
            putchar('1');
        else if (st[make_pair(l1[i], l2[i])] > 1)
            putchar('2');
        else
            putchar('3');
    }

    putchar('\n');
    return 0;
}