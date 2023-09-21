#include <bits/stdc++.h>

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

vector<int> n, m;

int main()
{
    int t = rr, k = rr;
    while (t--)
    {
        int a = rr, b = rr;
        while (a)
            n.push_back(a % k), b /= k;
        while (b)
            m.push_back(b % k), b /= k;
    }
    return 0;
}
