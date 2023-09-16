#include <bits/stdc++.h>

#define int long long
#define rr read()

using namespace std;

const int N = 1e5 + 10;

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

inline int MAX(const int &a, const int &b)
{
    return a > b ? a : b;
}

inline int ABS(const int &a)
{
    return a < 0 ? -a : a;
}

int f[N], s[N];
int mpre[N], mend[N];

signed main()
{
    int n = rr, k = rr;
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + rr, f[i] = MAX(s[i] - s[i - 1], 0);

    for (int i = 1; i <= n; ++i)
        mpre[i] = mpre[i - 1] + f[i];
    for (int i = n; i >= 1; --i)
        mend[i] = mend[i + 1] + f[i];

    int res = -4e18;
    for (int l = 1; l + k - 1 <= n; ++l)
        res = MAX(res, MAX(s[l + k - 1] - s[l - 1], 0) + mpre[l - 1] + mend[l + k]);

    printf("%lld\n", res);
    return 0;
}