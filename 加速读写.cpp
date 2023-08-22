#include <bits/stdc++.h>

using namespace std;

inline int read()
{
    int num = 0, flag = 1;
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

inline void write(int x)
{
    if (x == 0)
        putchar('0');
    else
    {
        if (x < 0)
            putchar('-'), x = -x;
        int stack[110], top = 0;
        while (x)
            stack[top++] = x % 10, x /= 10;
        while (top--)
            putchar(stack[top] + '0');
    }
    putchar('\n');
}

int main()
{
    freopen("copycat.in", "r", stdin);
    freopen("copycat.out", "w", stdout);

    int n = read();
    while (n--)
        write(read());

    fclose(stdin);
    fclose(stdout);
    return 0;
}