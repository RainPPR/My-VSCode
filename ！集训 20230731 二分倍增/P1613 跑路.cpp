#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const int K = 32;

int n, m;
int rG[N][N][K];
int G[N][N];

int dis[N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = rG[u][v][0] = 1;
    }

    for (int r = 1; r < K; ++r)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n && !rG[i][j][r]; ++k)
                    rG[i][j][r] |= rG[i][k][r - 1] && rG[k][j][r - 1], G[i][j] |= rG[i][j][r];

    queue<int> q;
    q.push(1);

    while (q.size())
    {
        int u = q.front();
        if (u == n)
            break;
        q.pop();

        for (int i = 1; i <= n; ++i)
            if (u != i && G[u][i] && !dis[i])
                dis[i] = dis[u] + 1, q.push(i);
    }

    printf("%d\n", dis[n]);
    return 0;
}