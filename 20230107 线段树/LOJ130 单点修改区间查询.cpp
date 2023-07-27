#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 4e6 + 10;

int a[N];

int m[N];

void build(int k, int l, int r)
{
    if (l == r)
    {
        m[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    m[k] = m[k * 2] + m[k * 2 + 1];
}

int query(int k, int l, int r, int x, int y)
{
    if (l > y || r < x)
        return 0;
    if (x <= l && r <= y)
        return m[k];
    int mid = (l + r) / 2;
    return query(k * 2, l, mid, x, y) + query(k * 2 + 1, mid + 1, r, x, y);
}

void modify(int k, int l, int r, int x, int v)
{
    if (l > x || r < x)
        return;
    if (l == x && r == x)
    {
        m[k] = a[x] = v;
        return;
    }
    int mid = (l + r) / 2;
    modify(k * 2, l, mid, x, v);
    modify(k * 2 + 1, mid + 1, r, x, v);
    m[k] = m[k * 2] + m[k * 2 + 1];
}

signed main()
{
    int n, q;
    scanf("%lld %lld", &n, &q);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);

    build(1, 1, n);

    while (q--)
    {
        int op;
        scanf("%lld", &op);

        if (op == 1)
        {
            int x, v;
            scanf("%lld %lld", &x, &v);
            modify(1, 1, n, x, a[x] + v);
        }
        else
        {
            int l, r;
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }

    return 0;
}