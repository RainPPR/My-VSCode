#include <bits/stdc++.h>

using namespace std;

template <typename _Tp>
_Tp read()
{
    _Tp num = 0, flag = 1;
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

int main()
{
    long long res = 0;
    for (int i = 1; i <= 3e6; ++i)
    {
        long long t;
        t = read<long long>();
        res ^= t;
    }
    printf("%lld\n", res);
    return 0;
}