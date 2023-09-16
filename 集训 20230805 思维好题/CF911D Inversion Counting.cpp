#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 2010;

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

int n, q;
int s[N];

inline int lobit(const int &x) { return x & -x; }

inline void insert(int x)
{
    for (; x <= n; x += lobit(x))
        ++s[x];
}

inline int query(int x)
{
    int res = 0;
    for (; x; x -= lobit(x))
        res += s[x];
    return res;
}

int main()
{
    n = rr;

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        int t = rr;
        res ^= i - query(t) & 1;
        insert(t);
    }

    q = rr;

    while (q--)
    {
        int l = rr, r = rr;
        res ^= ((r - l + 1) * (r - l) >> 1) & 1;
        printf(res & 1 ? "odd\n" : "even\n");
    }
    return 0;
}