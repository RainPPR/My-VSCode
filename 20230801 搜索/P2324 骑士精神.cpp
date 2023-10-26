#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int gcount[2][5] = {{0, 1, 2, 4, 5},
                          {5, 4, 2, 1, 0}};

string mp[5];

int f()
{
    int res = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < gcount[0][i]; ++j)
            if (mp[i][j] != '0')
                ++res;
        for (int j = 0; j < gcount[1][i]; ++j)
            if (mp[i][5 - j - 1] != '1')
                ++res;
    }
    return res;
}

bool ida_star(int now, int limit, int a, int b)
{
    int ct = f();
    if (now + ct > limit)
        return false;
    if (!ct)
        return true;

    for (int i = 0; i < 8; ++i)
    {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x < 0 || x > 4 || y < 0 || y > 4)
            continue;
        swap(mp[a][b], mp[x][y]);
        if (ida_star(now + 1, limit, x, y))
            return true;
        swap(mp[a][b], mp[x][y]);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int a = 0, b = 0;
        for (int i = 0; i < 5; ++i)
        {
            cin >> mp[i];
            for (int j = 0; j < 5; ++j)
                if (mp[i][j] == '*')
                    a = i, b = j;
        }

        int limit = 0;
        while (limit <= 15 && !ida_star(0, limit, a, b))
            ++limit;

        if (limit > 15)
            limit = -1;
        printf("%d\n", limit);
    }

    return 0;
}