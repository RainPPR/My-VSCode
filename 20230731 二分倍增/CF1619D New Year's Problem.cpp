#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int m, n;
unordered_map<int, int> p[N];

bool check(int mid)
{
    unordered_set<int> cg;
    bool istwo = false;

    for (int i = 1; i <= m; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (p[i][j] >= mid)
            {
                cg.insert(j);
                ++cnt;
            }
        }
        if (cnt >= 2)
            istwo = true;
    }

    return istwo && cg.size() == n;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d", &m, &n);
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int t;
                scanf("%d", &t);
                p[i][j] = t;
            }
        }

        int l = 0, r = 1e9;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }

        printf("%d\n", l);
    }

    return 0;
}