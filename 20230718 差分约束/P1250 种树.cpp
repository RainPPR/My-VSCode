// https://vjudge.csgrandeur.cn/problem/%E6%B4%9B%E8%B0%B7-P1250
// https://vjudge.csgrandeur.cn/problem/LibreOJ-10001

// s[i - 1] - s[i] >= -1
// s[i] - s[i - 1] >= 0
// s[b] - s[a - 1] >= c

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int s[N];

int h[N], e[N], w[N], ne[N], idx;

void add(int u, int v, int x)
{
    e[idx] = v;
    w[idx] = x;
    ne[idx] = h[u];
    h[u] = idx++;
}

int dis[N];
bool st[N];

void spfa(int x)
{
    queue<int> q;
    q.push(x);
    st[x] = true;
    dis[x] = 0;

    while (q.size())
    {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (dis[v] < dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];

                if (!st[v])
                {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    int n, h;
    scanf("%d", &n);
    scanf("%d", &h);

    int a, b, c;
    for (int i = 1; i <= h; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        add(a - 1, b, c);
    }

    for (int i = 1; i <= n; ++i)
    {
        dis[i] = -2e9;
        add(i, i - 1, -1);
        add(i - 1, i, 0);
    }

    spfa(0);

    printf("%d\n", dis[n]);
    return 0;
}