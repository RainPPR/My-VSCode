#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
const int M = N * 2;

namespace xdtree
{
    int a[M * 4];
    int m[M * 4];

    void modify(int k, int l, int r, int x, int v)
    {
        if (l > x || r < x)
            return;
        if (l == r)
        {
            a[x] = m[k] += v;
            return;
        }
        int mid = l + r >> 1;
        modify(k * 2, l, mid, x, v);
        modify(k * 2 + 1, mid + 1, r, x, v);
        m[k] = m[k * 2] + m[k * 2 + 1];
    }

    int query(int k, int l, int r, int x, int y)
    {
        if (l > y || r < x)
            return 0;
        if (l >= x && r <= y)
            return m[k];
        int mid = l + r >> 1;
        return query(k * 2, l, mid, x, y) + query(k * 2 + 1, mid + 1, r, x, y);
    }
}

namespace phtree
{
    void insert(int x)
    {
        xdtree::modify(1, 1, M, x + N, 1);
    }

    bool erase(int x)
    {
        if (!xdtree::a[x + N])
            return false;
        xdtree::modify(1, 1, M, x + N, -1);
        return true;
    }

    int rank(int x)
    {
        return xdtree::query(1, 1, M, 1, x + N - 1) + 1;
    }

    int th(int x)
    {
        int l = 1, r = M;
        while (l < r)
        {
            int mid = l + r >> 1;
            int lcnt = xdtree::query(1, 1, M, 1, mid);
            if (lcnt >= x)
                r = mid;
            else
                l = mid + 1;
        }
        return l - N;
    }

    int prev(int x)
    {
        return th(xdtree::query(1, 1, M, 1, x + N - 1));
    }

    int next(int x)
    {
        return th(xdtree::query(1, 1, M, 1, x + N) + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        int op, x;
        scanf("%d %d", &op, &x);

        switch (op)
        {
        case 1:
            phtree::insert(x);
            break;
        case 2:
            phtree::erase(x);
            break;
        case 3:
            printf("%d\n", phtree::rank(x));
            break;
        case 4:
            printf("%d\n", phtree::th(x));
            break;
        case 5:
            printf("%d\n", phtree::prev(x));
            break;
        case 6:
            printf("%d\n", phtree::next(x));
            break;
        }
    }

    return 0;
}
