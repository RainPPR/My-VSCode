#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n;

int h[N], w[N], e[N], ne[N], idx;

void add(int a, int b, int x)
{
    w[idx] = x;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dis[N];
bool st[N];
int cnt[N];

bool spfa(int x)
{
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);

    queue<int> q;
    q.push(x);
    st[x] = true;
    cnt[x] = 1;
    dis[x] = 0;

    while (q.size())
    {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                if (!st[v])
                {
                    q.push(v);
                    st[v] = true;
                    if (++cnt[v] >= n + 1)
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof h);

    int m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);

    for (int i = 1; i <= n; ++i)
        add(0, i, 0);

    for (int i = 1; i <= m1; ++i)
    {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        add(a, b, x);
    }

    for (int i = 1; i <= m2; ++i)
    {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        add(b, a, -x);
    }

    if (spfa(0) || spfa(1))
        printf("-1\n");
    else if (dis[n] == INF)
        printf("-2\n");
    else
        printf("%d\n", dis[n]);

    return 0;
}
