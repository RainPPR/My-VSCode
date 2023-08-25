#include <bits/stdc++.h>

#define int long long

#define rr read()

using namespace std;

const int N = 2e5 + 10;
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

int a[N], s[N];

int stk[N], top;
int ls[N], rs[N];

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

signed main()
{
    lg[1] = 0;
    for (int i = 2; i < N; ++i)
        lg[i] = lg[i >> 1] + 1;

    int T = rr;
    while (T--)
    {
        int n = rr;
        for (int i = 1; i <= n; ++i)
            a[i] = rr, f1[i][0] = f2[i][0] = s[i] = s[i - 1] + a[i];

        for (int j = 1; j < K; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 <= n; ++i)
            {
                f1[i][j] = max(f1[i][j - 1], f1[i + (1 << j - 1)][j - 1]);
                f2[i][j] = min(f2[i][j - 1], f2[i + (1 << j - 1)][j - 1]);
            }
        }

        int fc = 0;

        top = 0;
        for (int i = 1; i <= n; ++i)
        {
            while (top && a[i] >= a[stk[top]])
                --top;
            ls[i] = stk[top] + 1;
            stk[++top] = i;
        }

        top = 0;
        for (int i = n; i >= 1; --i)
        {
            while (top && a[i] >= a[stk[top]])
                --top;
            rs[i] = stk[top] ? stk[top] - 1 : n;
            stk[++top] = i;
        }

        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            int &l = ls[i], &r = rs[i];
            int t = q1(i, r) - q2(l - 1, i - 1);
            if (t > a[i])
            {
                flag = false;
                break;
            }
        }

        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}