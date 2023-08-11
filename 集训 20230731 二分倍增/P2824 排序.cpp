#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;

int n, m, x;
int a[N], q[N];
int op[N], ql[N], qr[N];

int cnt[N];
int s[N], mark[N];

void build(int k, int l, int r)
{
    if (l == r)
    {
        cnt[k] = 1;
        s[k] = q[l];
        mark[k] = -1;
        return;
    }
    int mid = l + r >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    cnt[k] = cnt[k * 2] + cnt[k * 2 + 1];
    s[k] = s[k * 2] + s[k * 2 + 1];
    mark[k] = -1;
}

void down(int k)
{
    if (mark[k] != -1)
    {
        s[k * 2] = mark[k] * cnt[k * 2];
        s[k * 2 + 1] = mark[k] * cnt[k * 2 + 1];
        mark[k * 2] = mark[k * 2 + 1] = mark[k];
        s[k * 2] = mark[k] * cnt[k * 2];
        mark[k] = -1;
    }
}

void modify(int k, int l, int r, int x, int y, int p)
{
    if (x > y)
        return;
    if (l > y || r < x)
        return;
    if (x <= l && y >= r)
    {
        s[k] = p * cnt[k];
        mark[k] = p;
        return;
    }

    down(k);

    int mid = l + r >> 1;
    modify(k * 2, l, mid, x, y, p);
    modify(k * 2 + 1, mid + 1, r, x, y, p);
    s[k] = s[k * 2] + s[k * 2 + 1];
}

int query(int k, int l, int r, int x, int y)
{
    if (x > y)
        return 0;
    if (l > y || r < x)
        return 0;
    if (x <= l && y >= r)
        return s[k];

    down(k);

    int mid = l + r >> 1;
    return query(k * 2, l, mid, x, y) + query(k * 2 + 1, mid + 1, r, x, y);
}

bool check(int mid)
{
    for (int i = 1; i <= n; ++i)
        q[i] = (a[i] >= mid);

    build(1, 1, n);

    for (int i = 1; i <= m; ++i)
    {
        if (op[i] == 0)
        {
            int t = query(1, 1, n, ql[i], qr[i]);
            modify(1, 1, n, ql[i], qr[i] - t, 0);
            modify(1, 1, n, qr[i] - t + 1, qr[i], 1);
        }
        else
        {
            int t = query(1, 1, n, ql[i], qr[i]);
            modify(1, 1, n, ql[i], ql[i] + t - 1, 1);
            modify(1, 1, n, ql[i] + t, qr[i], 0);
        }
    }

    return query(1, 1, n, x, x);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d %d %d", op + i, ql + i, qr + i);
    scanf("%d", &x);

    int l = 0, r = 1e5;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);

    return 0;
}