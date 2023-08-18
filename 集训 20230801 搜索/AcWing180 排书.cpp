#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n;
int q[N];
int w[5][N];

int f()
{
    int res = 0;
    for (int i = 0; i < n - 1; ++i)
        if (q[i + 1] != q[i] + 1)
            ++res;
    return (res + 2) / 3;
}

bool ida_star(int now, int limit)
{
    if (now + f() > limit)
        return false;
    if (f() == 0)
        return true;

    for (int len = 1; len <= n; ++len)
    {
        for (int l = 0; l + len - 1 < n; ++l)
        {
            int r = l + len - 1;
            for (int k = r + 1; k < n; ++k)
            {
                memcpy(w[now], q, sizeof q);

                int y = l;
                for (int x = r + 1; x <= k; ++x)
                    q[y++] = w[now][x];
                for (int x = l; x <= r; ++x)
                    q[y++] = w[now][x];

                if (ida_star(now + 1, limit))
                    return true;

                memcpy(q, w[now], sizeof q);
            }
        }
    }

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", q + i);

        int limit = 0;
        while (limit < 5 && !ida_star(0, limit))
            ++limit;

        if (limit >= 5)
            printf("5 or more\n");
        else
            printf("%d\n", limit);
    }

    return 0;
}