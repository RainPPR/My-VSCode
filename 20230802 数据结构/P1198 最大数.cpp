#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 8e5 + 10;
const int INF = 0x3f3f3f3f;

int m[N];

int query(int k, int l, int r, int x, int y)
{
    if (l > y || r < x)
        return -INF;
    if (x <= l && r <= y)
        return m[k];
    int mid = (l + r) / 2;
    return max(query(k * 2, l, mid, x, y), query(k * 2 + 1, mid + 1, r, x, y));
}

void modify(int k, int l, int r, int x, int v)
{
    if (l > x || r < x)
        return;
    if (l == x && r == x)
    {
        m[k] = v;
        return;
    }
    int mid = (l + r) / 2;
    modify(k * 2, l, mid, x, v);
    modify(k * 2 + 1, mid + 1, r, x, v);
    m[k] = max(m[k * 2], m[k * 2 + 1]);
}

signed main()
{
    memset(m, -1, sizeof m);

    int n, p, lt = 0;
    scanf("%lld %lld", &n, &p);

    int ed = 0;
    for (int i = 1; i <= n; ++i)
    {
        char op[2];
        scanf("%s", op);

        if (op[0] == 'Q')
        {
            int l;
            scanf("%lld", &l);
            lt = query(1, 1, n, ed - l + 1, ed);
            printf("%lld\n", lt);
        }
        else
        {
            int t;
            scanf("%lld", &t);
            modify(1, 1, n, ++ed, (t + lt) % p);
        }
    }

    return 0;
}