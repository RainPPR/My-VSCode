#include <bits/stdc++.h>

#define int long long
#define rr read()

using namespace std;

const int N = 2010;
const int M = N * N;

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

const int n = rr;
int sum;

bitset<M> f;

signed main()
{
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int t = rr;
        sum += t, f |= f << t;
    }

    for (int i = sum + 1 >> 1; i <= sum; ++i)
        if (f[i])
            printf("%lld\n", i), exit(0);

    return 0;
}