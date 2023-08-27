#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 110;
const int M = N * N;

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

struct node
{
    int a, b;
    bool operator<(const node &t) const
    {
        return b > t.b;
    }
} s[N];

int dp[N][M];

int main()
{
    int sumwater = 0, sumv = 0;

    int n = rr;
    for (int i = 1; i <= n; ++i)
        s[i].a = rr, sumwater += s[i].a;
    for (int i = 1; i <= n; ++i)
        s[i].b = rr, sumv += s[i].b;

    sort(s + 1, s + n + 1);

    int maxk = 0, t = sumwater;
    for (int i = 1; t > 0; ++i)
        t -= s[i].b, ++maxk;

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = maxk; j; --j)
            for (int k = sumv; k >= s[i].b; --k)
                if (dp[j - 1][k - s[i].b] != -1)
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - s[i].b] + s[i].a);

    int res = 0;
    for (int i = sumwater; i <= sumv; ++i)
        res = max(res, dp[maxk][i]);

    printf("%d %d\n", maxk, sumwater - res);
    return 0;
}