#include <bits/stdc++.h>

#define r read()

using namespace std;

const int N = 2010;
const int MOD = 998244353;

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

vector<pair<int, int>> g;

int f[N][N][2];

int main()
{
    int n = r, m = r, k = r, s = r, t = r, x = r, u, v;
    for (int i = 1; i <= m; ++i)
    {
        u = r, v = r;
        g.push_back({u, v}), g.push_back({v, u});
    }

    f[0][s][0] = 1;

    for (int i = 1; i <= k; ++i)
    {
        for (auto j : g)
        {
            u = j.first, v = j.second;
            for (int q = 0; q <= 1; ++q)
                f[i][u][q] = (f[i][u][q] + f[i - 1][v][q ^ (u == x)]) % MOD;
        }
    }

    printf("%d\n", f[k][t][0]);
    return 0;
}