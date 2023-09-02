#include <bits/stdc++.h>

#define int long long

#define rr read()

using namespace std;

const int N = 310;

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

int n;
int a[N][N];

int b[N][N];

signed main()
{
    n = rr;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = rr;

    int res = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (i == k || j == k)
                    continue;
                else if (a[i][j] > a[i][k] + a[k][j])
                    printf("-1\n"), exit(0);
                else if (a[i][j] == a[i][k] + a[k][j])
                    b[i][j] = 1;
            }
            if (!b[i][j])
                res += a[i][j];
        }
    }

    printf("%lld\n", res);
    return 0;
}