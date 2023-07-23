#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int h[N], w[N], e[N], ne[N], idx;

void add(int u, int v, int x)
{
    w[idx] = x;
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

int ans = -INF;

int dfs(int u, int fa)
{
    int m1 = 0, m2 = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        int d = dfs(v, u) + w[i];
        if (d >= m1)
            m2 = m1, m1 = d;
        else if (d > m2)
            m2 = d;
    }

    ans = max(ans, m1 + m2);
    return m1;
}

int main()
{
    memset(h, -1, sizeof h);

    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, -1);

    printf("%d\n", ans);
    return 0;
}