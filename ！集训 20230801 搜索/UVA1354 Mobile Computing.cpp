#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 21;
const int M = 1 << N;

int g[M];

ld wide;
int n, w[N];

namespace s1
{
    ld ans;
    int root, son[N][2];

    int node[N];

    void print(int k)
    {
        if (k == -1)
            return;
        if (son[k][0] != 0)
            cerr << k << " -> " << son[k][0] << endl, print(son[k][0]);
        if (son[k][1] != 0)
            cerr << k << " -> " << son[k][1] << endl, print(son[k][1]);
    }

    namespace check
    {
        ld lest, rest;

        void eval(int root, ld pos)
        {
            lest = min(lest, pos);
            rest = max(rest, pos);

            int l = son[root][0], r = son[root][1];
            if (!l && !r)
                return;

            ld ldis = node[r] / ld(node[l] + node[r]);
            eval(l, pos - ldis);
            eval(r, pos - ldis + 1);
        }

        ld calc()
        {
            lest = 2e9, rest = -2e9;
            eval(2 * n - 1, 0);
            return rest - lest;
        }
    }

    void dfs(int now, int cnt)
    {
        if (cnt == 2 * n - 1)
        {
            ld res = check::calc();
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

                node[root] = node[l] + node[r];
                son[root][0] = l, son[root][1] = r;

                dfs(now | (1 << (l - 1)) | (1 << (r - 1)), root);
            }
        }
    }

    ld solve()
    {
        memset(son, 0, sizeof son);
        ans = -1;
        for (int i = 1; i <= n; ++i)
            node[i] = w[i];
        dfs(0, n);
        return ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < M; ++i)
        g[i] = g[i & (i - 1)] + 1;

    int T;
    cin >> T;

    while (T--)
    {
        cin >> wide >> n;
        for (int i = 1; i <= n; ++i)
            cin >> w[i];

        ld ans = s1::solve();
        if (ans == -1)
            printf("-1\n");
        else
            printf("%.16LF\n", s1::solve());
    }
    return 0;
}