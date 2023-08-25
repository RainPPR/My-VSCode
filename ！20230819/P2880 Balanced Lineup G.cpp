#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 5e4 + 10;
const int K = 16;

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

int lg[N];
int f1[N][K], f2[N][K];

int q1(int l, int r)
{
    int len = r - l + 1;
    int k = lg[len];
    return max(f1[l][k], f1[r - (1 << k) + 1][k]);
}

int q2(int l, int r)
{
    int len = r - l + 1;
    int k = lg[len];
    return min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

int main()
{
    lg[1] = 0;
    for (int i = 2; i < N; ++i)
        lg[i] = lg[i >> 1] + 1;

    int n = rr, q = rr;
    for (int i = 1; i <= n; ++i)
        f1[i][0] = f2[i][0] = rr;

    for (int j = 1; j < K; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            f1[i][j] = max(f1[i][j - 1], f1[i + (1 << j - 1)][j - 1]);
            f2[i][j] = min(f2[i][j - 1], f2[i + (1 << j - 1)][j - 1]);
        }
    }

    while (q--)
    {
        int l = rr, r = rr;
        cerr << q1(l, r) << " " << q2(l, r) << endl;
        printf("%d\n", q1(l, r) - q2(l, r));
    }
    return 0;
}