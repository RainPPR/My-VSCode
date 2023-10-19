#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
struct edge
{
    int a, b, v, p;
} edges[N];

double w[N];
int h[N], e[N], ne[N], idx;
void add(int u, int v, double x)
{
    e[idx] = v;
    w[idx] = x;
    ne[idx] = h[u];
    h[u] = idx++;
}

double dis[N], vis[N];
bool dfs_spfa(int u) {
    if (vis[u]) return true;
    vis[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) if (dis[e[i]] > dis[u] + w[i]) {
        dis[e[i]] = dis[u] + w[i];
        if (dfs_spfa(e[i])) { vis[u] = false; return true; }
    } vis[u] = false; return false;
} bool check(double mid) {
    idx = 0; memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i) add(0, i, 0);
    int w; for (int i = 1; i <= m; ++i) w = edges[i].p * mid - edges[i].v, add(edges[i].a, edges[i].b, w), add(edges[i].a, edges[i].b, w);
    memset(dis, 0x3f, sizeof dis); dis[0] = 0;
    return dfs_spfa(0);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d %d %d %d", &edges[i].a, &edges[i].b, &edges[i].v, &edges[i].p);

    double ans = -1;
    double l = 0, r = 200;
    while (l + 1e-4 < r)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid, ans = mid;
        else
            r = mid;
    }

    if (ans == -1)
        printf("-1\n");
    else
        printf("%.1lf\n", ans);
    return 0;
}