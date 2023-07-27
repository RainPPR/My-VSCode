#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 4e5 + 10;
const int INF = 0x3f3f3f3f;

int a[N];

int m[N], c[N];
int ad[N];

void build(int k, int l, int r)
{
    if (l == r)
    {
        m[k] = a[l];
        c[k] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    c[k] = c[k * 2] + c[k * 2 + 1];
    m[k] = m[k * 2] + m[k * 2 + 1];
}

void pd(int k)
{
    if (!ad[k])
        return;
    ad[k * 2] += ad[k];
    ad[k * 2 + 1] += ad[k];
    m[k * 2] += ad[k] * c[k * 2];
    m[k * 2 + 1] += ad[k] * c[k * 2 + 1];
    ad[k] = 0;
}

int query(int k, int l, int r, int x, int y)
{
    if (x > r || y < l)
        return 0;
    if (x <= l && y >= r)
        return m[k];

    pd(k);

    int mid = (l + r) / 2;
    return query(k * 2, l, mid, x, y) + query(k * 2 + 1, mid + 1, r, x, y);
}

void modify(int k, int l, int r, int x, int y, int v)
{
    if (x > r || y < l)
        return;
    if (x <= l && y >= r)
    {
        ad[k] += v;
        m[k] += v * c[k];
        return;
    }

    pd(k);

    int mid = (l + r) / 2;
    modify(k * 2, l, mid, x, y, v);
    modify(k * 2 + 1, mid + 1, r, x, y, v);
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
        char op[2];
        scanf("%s", op);

        if (op[0] == 'C')
        {
            int x, y, v;
            scanf("%lld %lld %lld", &x, &y, &v);
            modify(1, 1, n, x, y, v);
        }
        else
        {
            int x, y;
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }

    return 0;
}