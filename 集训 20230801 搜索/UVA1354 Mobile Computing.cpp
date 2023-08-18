#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 21;

ld wide;
int n, w[N];

int son[N][2];
ld ans, lest, rest;

void eval(int root, ld pos)
{
    if (pos < lest)
        lest = pos;
    if (pos > rest)
        rest = pos;

    int l = son[root][0], r = son[root][1];
    if (!l && !r)
        return;

    ld ldis = w[r] / ld(w[l] + w[r]);
    eval(l, pos - ldis);
    eval(r, pos - ldis + 1);
}

void dfs(int now, int cnt)
{
    if (cnt == 2 * n - 1)
    {
        lest = 2e9, rest = -2e9;
        eval(2 * n - 1, 0);
        ld res = rest - lest;
        if (res <= wide && res > ans)
            ans = res;
        return;
    }

    for (int l = 1; l <= cnt; ++l)
    {
        if (now & (1 << (l - 1)))
            continue;
        for (int r = 1; r <= cnt; ++r)
        {
            if ((l == r) || (now & (1 << (r - 1))))
                continue;

            int root = cnt + 1;

            w[root] = w[l] + w[r];
            son[root][0] = l, son[root][1] = r;

            dfs(now | (1 << (l - 1)) | (1 << (r - 1)), root);

            son[root][0] = 0, son[root][1] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> wide >> n;
        for (int i = 1; i <= n; ++i)
            cin >> w[i];

        ans = -1;
        dfs(0, n);

        if (ans == -1)
            printf("-1\n");
        else
            printf("%.16LF\n", ans);
    }
    return 0;
}
