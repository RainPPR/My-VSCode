#include <bits/stdc++.h>

#define rr read()
#define rl readline()
#define min MIN
#define max MAX

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

inline string readline()
{
    char ch = getchar();
    while (ch == '\n' || ch == '\r')
        ch = getchar();
    string str;
    while (ch != '\n' && ch != '\r')
        str.push_back(ch), ch = getchar();
    return str;
}

inline int MAX(const int &a, const int &b)
{
    return a > b ? a : b;
}

inline int MIN(const int &a, const int &b)
{
    return a < b ? a : b;
}

int main()
{
    int n = rr + 1, k = rr;
    string str = rl + "c";

    int c[3] = {0}, res = 0;

    int l = 0, r = 0;
    while (l < n)
    {
        while (r < n && min(c[0], c[1]) <= k)
            ++c[str[r] - 'a'], ++r;
        res = max(res, r - l - 1);
        do
            --c[str[l] - 'a'], ++l;
        while (l < r && min(c[0], c[1]) > k);
    }

    printf("%d\n", res);
    return 0;
}
