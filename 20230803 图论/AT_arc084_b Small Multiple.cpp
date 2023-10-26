#include <bits/stdc++.h>

#define rr read()

using namespace std;

const int N = 3e5 + 10;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

int k;

int h[N], e[N], ne[N], w[N], idx;

void add(int u, int v, int x)
{
    e[idx] = v;
    w[idx] = x;
    ne[idx] = h[u];
    h[u] = idx++;
}

int dis[N];
bool st[N];

void bfs()
{
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        st[u] = 0;

        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                if (!st[v])
                    q.push(v);
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);

    k = rr;

    add(0, 1, 1);
    for (int i = 1; i <= k; ++i)
        add(i, (i + 1) % k, 1), add(i, i * 10 % k, 0);

    bfs();

    printf("%d\n", dis[0] + 1);
    return 0;
}