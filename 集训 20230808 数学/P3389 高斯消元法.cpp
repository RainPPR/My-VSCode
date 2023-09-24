#include <bits/stdc++.h>

#define fabs ABS
#define rr read()

using namespace std;

const int N = 110;

inline long long read()
{
    long long num = 0, flag = 1;
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

    for (int i = 1; i <= n; ++i)
    {
        int r = 0;
        for (int j = i; j <= n; ++j)
            if (fabs(a[j][i]) > fabs(a[r][i]))
                r = j;

        if (a[r][i] == 0)
            printf("No Solution\n"), exit(0);

        const double t = a[r][i];
        for (int j = 1; j <= n; ++j)
            swap(a[i][j], a[r][j]), a[i][j] /= t;
        swap(b[i], b[r]), b[i] /= t;

        for (int j = 1; j <= n; ++j)
        {
            if (i == j || a[j][i] == 0)
                continue;
            const double c = a[j][i];
            for (int k = i; k <= n; ++k)
                a[j][k] -= c * a[i][k];
            b[j] -= c * b[i];
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%.2lf\n", b[i]);
    return 0;
}
