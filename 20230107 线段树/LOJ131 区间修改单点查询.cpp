#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 4e6 + 10;

int a[N];

int m[N];
int ad[N];

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

int query(int k, int l, int r, int p)
{
    if (l == r)
        return m[k] + ad[k];
    int mid = (l + r) / 2;
    if (p <= mid)
        return query(k * 2, l, mid, p) + ad[k];
    else
        return query(k * 2 + 1, mid + 1, r, p) + ad[k];
}

void modify(int k, int l, int r, int x, int y, int v)
{
    if (r < x || l > y)
        return;
    if (x <= l && y >= r)
    {
        ad[k] += v;
        return;
    }
    int mid = (l + r) / 2;
    modify(k * 2, l, mid, x, y, v);
    modify(k * 2 + 1, mid + 1, r, x, y, v);
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
            int l, r, v;
            scanf("%lld %lld %lld", &l, &r, &v);
            modify(1, 1, n, l, r, v);
        }
        else
        {
            int x;
            scanf("%lld", &x);
            printf("%lld\n", query(1, 1, n, x));
        }
    }

    return 0;
}