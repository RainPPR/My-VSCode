#include <bits/stdc++.h>

#define fabs ABS
#define rr read()

using namespace std;

const int N = 55;

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

inline double ABS(const double &x) { return x < 0 ? -x : x; }

double a[N][N], b[N];

int main()
{
    int n = rr;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            a[i][j] = rr;
        b[i] = rr;
    }

    int row = 1;
    for (int col = 1; col <= n; ++col)
    {
        int mi = 0;
        double cm = -1;

        for (int i = row; i <= n; ++i)
            if (fabs(a[i][col]) > cm)
                cm = fabs(a[i][col]), mi = i;

        if (a[mi][col] == 0)
            continue;

        const double t = a[mi][col];
        for (int i = 1; i <= n; ++i)
            swap(a[row][i], a[mi][i]), a[row][i] /= t;
        swap(b[row], b[mi]), b[row] /= t;

        for (int i = 1; i <= n; ++i)
        {
            if (i == row || a[i][col] == 0)
                continue;
            const double c = a[i][col];
            for (int j = 1; j <= n; ++j)
                a[i][j] -= c * a[row][j];
            b[i] -= c * b[row];
        }

        ++row;
    }

    if (row == n + 1)
    {
        for (int i = 1; i <= n; ++i)
            printf("x%d=%.2lf\n", i, b[i]);
        exit(0);
    }

    for (int i = row; i <= n; ++i)
        if (b[i] != 0)
            printf("-1\n"), exit(0);

    printf("0\n");
    return 0;
}
