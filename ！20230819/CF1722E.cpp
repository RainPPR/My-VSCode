#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 1010;

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

int s[N][N];

int main()
{
    int T = rr;
    while (T--)
    {
        memset(s, 0, sizeof s);

        int n = rr, q = rr;
        for (int i = 1; i <= n; ++i)
        {
            int x = rr, y = rr;
            s[x][y] = x * y;
        }

        for (int x = 1; x <= 1000; ++x)
            for (int y = 1; y <= 1000; ++y)
                s[x][y] += s[x][y - 1] + s[x - 1][y] - s[x - 1][y - 1];

        for (int i = 1; i <= q; ++i)
        {
            int x0 = rr, y0 = rr, x1 = rr, y1 = rr;
            printf("%d\n", s[x1][y1] - s[x0 - 1][y1] - s[x1][y0 - 1] + s[x0 - 1][y0 - 1]);
        }
    }
    return 0;
}