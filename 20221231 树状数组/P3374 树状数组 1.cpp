#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

inline int lobit(int x)
{
    return x & -x;
}

int n;
int a[N];

void add(int x, int y)
{
    for (int i = x; i <= n; i += lobit(i))
        a[i] += y;
}

int sum(int r)
{
    int res = 0;
    for (int i = r; i; i -= lobit(i))
        res += a[i];
    return res;
}

int sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

int main()
{
    int q;
    scanf("%d %d", &n, &q);

    int t;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &t);
        add(i, t);
    }

    while (q--)
    {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1)
            add(x, y);
        else
            printf("%d\n", sum(x, y));
    }

    return 0;
}