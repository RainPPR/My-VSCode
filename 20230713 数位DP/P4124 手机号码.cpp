#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 12;

int a[N];
int f[N][N][N][2][2][2];

int len;

int dfs(int pos, int last1, int last2, bool limit, bool same, bool have4, bool have8)
{
    if (!pos)
        return same && !(have4 && have8);

    auto &now = f[pos][last1][last2][same][have4][have8];
    if (!limit && ~now)
        return now;

    int down = (pos == len);
    int up = limit ? a[pos] : 9;

    int res = 0;
    for (int i = down; i <= up; ++i)
    {
        bool st = same || (last1 == i && last2 == i);
        if (i == 4 && !have8)
            res += dfs(pos - 1, i, last1, limit && i == up, st, true, false);
        else if (i == 8 && !have4)
            res += dfs(pos - 1, i, last1, limit && i == up, st, false, true);
        else if (i != 4 && i != 8)
            res += dfs(pos - 1, i, last1, limit && i == up, st, have4, have8);
    }

    if (!limit)
        now = res;
    return res;
}

int solve(int x)
{
    len = 0;
    while (x)
    {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, 10, 10, true, false, false, false);
}

signed main()
{
    memset(f, -1, sizeof f);

    int l, r;
    scanf("%lld %lld", &l, &r);

    bool flag = (l == 1e10);

    printf("%lld\n", solve(r) - solve(l - 1 + flag) + flag);
    return 0;
}