#include <bits/stdc++.h>

using namespace std;

const int N = 110;

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

int n;
int path[N];

int main()
{
    path[0] = 1;
    while (n = read())
    {
        int depth = 1;
        while (!iddfs(0, depth))
            ++depth;
    }
    return 0;
}
