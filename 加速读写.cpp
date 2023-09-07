#include <bits/stdc++.h>

#define rr read()
#define rl readline()
#define rw readword()

#define ww(x) write(x)
#define wl(x) writeline(x)

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
    string str;
    char ch = getchar();
    while (ch <= 13)
        ch = getchar();
    while (ch > 13)
        str += ch, ch = getchar();
    return str;
}

inline bool iswordsep(const char &ch)
{
    return ch <= ' ';
}

inline string readword()
{
    string str;
    char ch = getchar();
    while (iswordsep(ch))
        ch = getchar();
    while (!iswordsep(ch))
        str += ch, ch = getchar();
    return str;
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

inline void writeline(string str)
{
    while (str.back() <= 13)
        str.pop_back();
    for (char ch : str)
        putchar(ch);
    putchar('\n');
}

int main()
{
    freopen("copycat.in", "r", stdin);
    freopen("copycat.out", "w", stdout);

    int n = rr;
    while (n--)
        wl(rl);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
