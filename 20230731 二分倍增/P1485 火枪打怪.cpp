// https://www.luogu.com.cn/blog/RainPPR/solution-p1485

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 10;

int read()
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

int n, k;
int m[N];

int c[N];
int cj[N];
int cjj[N];

int getd(int i, int j, int p)
{
    return (p - i * i) * (c[i] - c[j]) + 2 * i * (cj[i] - cj[j]) - (cjj[i] - cjj[j]);
}

bool check(int p)
{
    int x = sqrt(p), res = k;
    for (int i = n; i >= 1; --i)
    {
        int D = getd(i, i + x, p);
        int cnt = (max(m[i] - D, -p) + p) / p;

        if ((res -= cnt) < 0)
            return false;

        c[i - 1] = c[i] + cnt;
        cj[i - 1] = cj[i] + cnt * i;
        cjj[i - 1] = cjj[i] + cnt * i * i;
    }
    return true;
}

signed main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; ++i)
        m[i] = read();

    int l = 1, r = 1e11;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    printf("%lld\n", l);
    return 0;
}