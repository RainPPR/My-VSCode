#include <bits/stdc++.h>

using namespace std;

const int N = 510;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m;
int a[N][N];

bool vis[N][N][N];

vector<pair<int, int>> nodes;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);

    queue<pair<int, int>> q;
    for (int start = 1; start <= m; ++start)
    {
        q.push({1, start});
        vis[0][1][start] = true;
        vis[start][1][start] = true;

        while (q.size())
        {
            auto now = q.front();
            int x = now.first, y = now.second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];

                if (tx < 1 || tx > n || ty < 1 || ty > m || vis[start][tx][ty])
                    continue;
                if (a[tx][ty] < a[x][y])
                    q.push({tx, ty}), vis[0][tx][ty] = 1, vis[start][tx][ty] = 1;
            }
        }

        vector<int> g;
        for (int i = 1; i <= m; ++i)
            if (vis[start][n][i])
                g.push_back(i);

        if (g.size())
            nodes.push_back({g.front(), g.back()});
    }

    int connected = 0;
    for (int i = 1; i <= m; ++i)
        connected += vis[0][n][i];

    if (connected < m)
        printf("0\n%d\n", m - connected);
    else
    {
        sort(nodes.begin(), nodes.end());

        int now = 1, res = 0;
        for (size_t i = 0; i < nodes.size(); ++i, ++res)
        {
            while (nodes[i].first <= now)
                ++i;
            now = nodes[i - 1].second + 1;
        }

        printf("1\n%d\n", res);
    }

    return 0;
}