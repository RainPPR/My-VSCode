#include <bits/stdc++.h>

#define rr read()

using namespace std;

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

const int N = 1e5 + 10;
const int K = 17;

int n, m;

int lg[N];
int f[N][K];

int query(int l, int r)
{
    int len = r - l + 1;
    int k = lg[len];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    lg[1] = 0;
    for (int i = 2; i < N; ++i)
        lg[i] = lg[i >> 1] + 1;

    n = rr, m = rr;
    for (int i = 1; i <= n; ++i)
        f[i][0] = rr;

    for (int j = 1; j < K; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);

    while (m--)
    {
        int l = rr, r = rr;
        printf("%d\n", query(l, r));
    }
    return 0;
}