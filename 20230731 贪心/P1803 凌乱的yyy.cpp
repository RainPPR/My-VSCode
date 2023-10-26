#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

struct node
{
    int l, r;
    bool operator<(const node &t) const
    {
        return r < t.r;
    }
} nodes[N];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &nodes[i].l, &nodes[i].r);

    sort(nodes + 1, nodes + n + 1);

    int now = -1, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (nodes[i].l >= now)
            now = nodes[i].r, ++cnt;
    }

    printf("%d\n", cnt);
    return 0;
}