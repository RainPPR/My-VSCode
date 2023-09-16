#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 510;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

int d[N][N];
int in[N];

int main()
{
    vector<int> rk;

    int T = rr;
    while (T--)
    {
        rk.clear();
        memset(d, 0, sizeof d);

        int n = rr;
        for (int i = 0; i < n; ++i)
        {
            int t = rr;
            for (int j : rk)
                d[j][t] = 1;
            in[t] = i, rk.push_back(t);
        }

        int m = rr;
        for (int i = 0; i < m; ++i)
        {
            int s = rr, t = rr;
            if (d[t][s])
                swap(s, t);
            ++in[s], --in[t];
            d[s][t] = 0, d[t][s] = 1;
        }

        int z = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (!in[i])
            {
                z = i;
                break;
            }
        }

        if (z == -1)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        queue<int> q;
        q.push(z);

        vector<int> ans;
        while (q.size())
        {
            int top = q.front();
            q.pop();

            ans.push_back(top);
            for (int v = 1; v <= n; ++v)
            {
                if (!d[top][v] || --in[v] != 0)
                    continue;
                q.push(v);
            }
        }

        if (ans.size() != n)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); ++i)
            printf(" %d", ans[i]);
        putchar('\n');
    }

    return 0;
}