#include <bits/stdc++.h>

#define abs ABS
#define rr read()

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

inline int ABS(const int &t) { return t < 0 ? -t : t; }
inline int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
        tmp = b, b = a % b, a = tmp;
    return a;
}

int main()
{
    int n = rr;

    int t = gcd(abs(rr), abs(rr));
    for (int i = 3; i <= n; ++i)
        t = gcd(t, abs(rr));

    printf("%d\n", t);
    return 0;
}
