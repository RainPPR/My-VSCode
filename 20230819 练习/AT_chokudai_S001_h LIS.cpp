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

int lobit(int x)
{
    return x & -x;
}

int n;
int a[N];

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

int main()
{
    n = rr;

    int len = 1;
    for (int i = 1; i <= n; ++i)
    {
        int t = rr;

        int r = qry(t) + 1;
        upd(t, r);
        len = max(len, r);
    }

    printf("%d\n", len);
    return 0;
}