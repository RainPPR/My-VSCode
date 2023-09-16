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
        num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

int f[N];

int main()
{
    int n = rr, m = 0;

    while (n--)
        if (++f[rr] == 1)
            ++m;

    m -= (m & 1) ^ 1;

    printf("%d\n", m);
    return 0;
}
