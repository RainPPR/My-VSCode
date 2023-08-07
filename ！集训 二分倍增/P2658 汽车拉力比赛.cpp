#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int h[N][N];

vector<int> pos;

int f[N * N];

int find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    f[x] = y;
}

int geti(int x, int y)
{
    return x * N + y;
}

bool check(int d)
{
    for (int i = 1; i < N * N; ++i)
        f[i] = i;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (abs(h[i][j] - h[i + 1][j]) <= d)
                merge(geti(i, j), geti(i + 1, j));
            if (abs(h[i][j] - h[i][j + 1]) <= d)
                merge(geti(i, j), geti(i, j + 1));
        }
    }

    for (int i = 1; i < pos.size(); ++i)
        if (find(pos[i - 1]) != find(pos[i]))
            return false;
    return true;
}

int main()
{
    // freopen("ccski.in", "r", stdin);
    // freopen("ccski.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", h[i] + j);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int k;
            scanf("%d", &k);
            if (k == 1)
                pos.push_back(geti(i, j));
        }
    }

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    printf("%d\n", l);

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}