#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 1e8 + 10;
const int M = 6e6 + 10;

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

int prime[M], cnt;
bool is[N];

int main()
{
    int n = rr, q = rr;
    for (int i = 2; i <= n; ++i)
    {
        if (!is[i])
            prime[++cnt] = i;
        for (int j = 1; prime[j] <= n / i; ++j)
        {
            is[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }

    while (q--)
        printf("%d\n", prime[rr]);
    return 0;
}