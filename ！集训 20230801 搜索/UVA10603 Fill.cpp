#include <bits/stdc++.h>

using namespace std;

const int N = 210;

struct point
{
    int a, b;
    point()
    {
        a = b = 0;
    }
    point(int _a, int _b)
    {
        a = _a, b = _b;
    }
    bool operator<(const point &t) const
    {
        return (a == t.a) ? (b < t.b) : (a < t.a);
    }
};

int a, b, c, d;

int vis[N][N];
int dis[N][N];

point change(point k, int op, int &r)
{
    switch (op)
    {
    case 0:
    {
        // a -> b
        r = min(k.a, b - k.b);
        k.b += r;
        k.a -= r;
        break;
    }
    case 1:
    {
        // a -> c
        r = min(k.a, k.a + k.b);
        k.a -= r;
        break;
    }
    case 2:
    {
        // b -> a
        r = min(k.b, a - k.a);
        k.a += r;
        k.b -= r;
        break;
    }
    case 3:
    {
        // b -> c
        r = min(k.b, k.a + k.b);
        k.b -= r;
        break;
    }
    case 4:
    {
        // c -> a
        r = min(c - k.a - k.b, a - k.a);
        k.a += r;
        break;
    }
    case 5:
    {
        // c -> b
        r = min(c - k.a - k.b, b - k.b);
        k.b += r;
        break;
    }
    }
    return k;
}

void Dijkstra()
{
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);

    priority_queue<pair<int, point>, vector<pair<int, point>>, greater<pair<int, point>>> q;

    q.push(make_pair(0, point(0, 0)));
    dis[0][0] = 0;

    while (q.size())
    {
        int d = q.top().first;
        point u = q.top().second;
        q.pop();

        if (vis[u.a][u.b])
            continue;
        vis[u.a][u.b] = true;

        for (int op = 0; op < 6; ++op)
        {
            int r = 0;
            point v = change(u, op, r);
            if (dis[v.a][v.b] > d + r)
            {
                dis[v.a][v.b] = d + r;
                q.push({dis[v.a][v.b], v});
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        Dijkstra();

        int ans = 0x3f3f3f3f;
        while (ans == 0x3f3f3f3f)
        {
            for (int i = 0; i <= c - d; ++i)
                ans = min(ans, dis[i][d]);
            for (int i = 0; i <= c - d; ++i)
                ans = min(ans, dis[d][i]);
            for (int i = 0; i <= c - d; ++i)
                ans = min(ans, dis[i][c - d - i]);
            --d;
        }
        printf("%d %d\n", ans, d + 1);
    }
    return 0;
}