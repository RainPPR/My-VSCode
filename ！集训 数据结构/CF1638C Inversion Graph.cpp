#include <bits/stdc++.h>

#define int long long

using namespace std;

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

signed main()
{
    int T = read();
    while (T--)
    {
        int n = read();

        int sum = 0, res = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum += read();
            if ((sum << 1) == i * (i + 1))
                ++res;
        }

        printf("%lld\n", res);
    }
    return 0;
}