#include <bits/stdc++.h>

#define rr read()
#define rl readline()

using namespace std;

constexpr int M = 8000;
constexpr int N = M + 10;

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

bitset<N * 2> dp[2];

int main()
{
    string op = rl;
    int x = rr, y = rr;

    int i = 0;
    for (; i < op.size(); ++i)
        if (op[i] == 'T')
            break;

    dp[0][i + M] = dp[1][M] = 1;

    int s = 0, p = 0;
    for (; i < op.size(); ++i)
    {
        if (op[i] == 'F')
            ++s;
        else
        {
            dp[p] = (dp[p] << s) | (dp[p] >> s);
            s = 0, p ^= 1;
        }
    }

    if (s)
        dp[p] = (dp[p] << s) | (dp[p] >> s);

    printf((dp[0][x + M] & dp[1][y + M]) ? "Yes" : "No");
    return 0;
}
