#include <bits/stdc++.h>

#define rr read()

#define m_debug 0

using namespace std;

const int N = 2.5e5 + 10;
const int K = 18;

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

int lg[K];
int a[N][K], b[N][K];

int maxa(int l, int r)
{
    int k = lg[r - l + 1];
    return max(a[l][k], a[r - (1 << k) + 1][k]);
}

int maxb(int l, int r)
{
    int k = lg[r - l + 1];
    return max(b[l][k], b[r - (1 << k) + 1][k]);
}

int main()
{
#ifndef mdebug
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
#endif

    lg[1] = 0;
    for (int i = 2; i < K; ++i)
        lg[i] = lg[i >> 1] + 1;

    int T = rr, n = rr;
    for (int i = 1; i <= n; ++i)
        a[i][0] = rr;
    for (int i = 1; i <= n; ++i)
        b[i][0] = rr;

    for (int j = 1; j < K; ++j)
        for (int i = 1; i <= n; ++i)
            a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]), b[i][j] = max(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);

    int Q = rr;
    while (Q--)
    {
        unsigned long long res = 0;

        int l = rr, r = rr;
        for (int i = l; i <= r; ++i)
            for (int j = i; j <= r; ++j)
                res += 1ull * maxa(i, j) * maxb(i, j);

        printf("%llu\n", res);
    }

#ifndef mdebug
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
