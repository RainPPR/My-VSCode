#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;
const int W = 1e5 + 10;

int n, m, q;

vector<pair<int, int>> G[W];

int qx[N], qy[N], qt;
bool qover[N];

int l[N], r[N];

struct cmp
{
    bool operator()(const int &k1, const int &k2) const
    {
        return (l[k1] + r[k1] >> 1) < (l[k2] + r[k2] >> 1);
    }
};

int fa[N];

int find(int x)
{
    return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    fa[x] = y;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[w].push_back(make_pair(u, v));
    }

    scanf("%d", &q);

    for (int i = 1; i <= q; ++i)
    {
        scanf("%d %d", qx + i, qy + i);
        l[i] = 0, r[i] = 1e5;
    }

    qt = q;

    while (qt)
    {
        for (int i = 1; i <= n; ++i)
            fa[i] = i;

        priority_queue<int, vector<int>, cmp> heap;
        for (int i = 1; i <= q; ++i)
            if (!qover[i])
                heap.push(i);

        int now = W;
        while (heap.size())
        {
            int i = heap.top();
            heap.pop();

            if (l[i] >= r[i])
            {
                qover[i] = true;
                --qt;
                continue;
            }

            int mid = l[i] + r[i] + 1 >> 1;
            for (int j = now - 1; j >= mid; --j)
                for (pair<int, int> k : G[j])
                    merge(k.first, k.second);

            if (find(qx[i]) == find(qy[i]))
                l[i] = mid;
            else
                r[i] = mid - 1;

            now = mid;
        }
    }

    for (int i = 1; i <= q; ++i)
        if (l[i] == 0)
            printf("-1\n");
        else
            printf("%d\n", l[i]);

    return 0;
}