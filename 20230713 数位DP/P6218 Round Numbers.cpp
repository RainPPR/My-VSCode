#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int a[N];
int f[N][N][N];

int dfs(int pos, bool limit, int n0, int n1, bool lead0)
{
    if (!pos)
        return n0 >= n1;
    int &now = f[pos][n0][n1];
    if (!limit && ~now)
        return now;

    int up = limit ? a[pos] : 1;

    int res = 0;
    for (int i = 0; i <= up; ++i)
    {
        int suf0 = lead0 && i == 0;
        int t0 = suf0 ? 0 : n0 + !i;
        int t1 = suf0 ? 0 : n1 + i;
        res += dfs(pos - 1, limit && i == up, t0, t1, suf0);
    }

    if (!limit)
        now = res;
    return res;
}

int solve(int x)
{
    int len = 0;
    while (x)
    {
        a[++len] = x & 1;
        x >>= 1;
    }
    return dfs(len, true, 0, 0, true);
}

int main()
{
    memset(f, -1, sizeof f);

    int l, r;
    scanf("%d %d", &l, &r);

    printf("%d\n", solve(r) - solve(l - 1));
    return 0;
}
