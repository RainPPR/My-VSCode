#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int INF = 1e9;

int a[N];
int f[N][10];

int dfs(int pos, int last, bool limit, bool lead0)
{
    if (!pos)
        return 1;
    if (!limit && last != INF && ~f[pos][last])
        return f[pos][last];

    int up = limit ? a[pos] : 9;

    int res = 0;
    for (int i = 0; i <= up; ++i)
    {
        if (lead0)
        {
            if (i == 0)
                res += dfs(pos - 1, last, false, true);
            else
                res += dfs(pos - 1, i, limit && i == up, false);
        }
        else if (abs(i - last) >= 2)
            res += dfs(pos - 1, i, limit && i == up, false);
    }

    if (!limit && last != INF)
        f[pos][last] = res;
    return res;
}

int query(int x)
{
    int cnt = 0;
    while (x)
    {
        a[++cnt] = x % 10;
        x /= 10;
    }
    return dfs(cnt, INF, true, true);
}

int main()
{
    memset(f, -1, sizeof f);

    int l, r;
    scanf("%d %d", &l, &r);

    printf("%d\n", query(r) - query(l - 1));
    return 0;
}