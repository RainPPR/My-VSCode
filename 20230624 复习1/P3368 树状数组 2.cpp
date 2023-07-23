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

int main()
{
    int q;
    scanf("%d %d", &n, &q);

    int t;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &t);
        add(i, t);
        add(i + 1, -t);
    }

    while (q--)
    {
        int op;
        scanf("%d", &op);

        if (op == 1)
        {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);
            add(x, k);
            add(y + 1, -k);
        }
        else
        {
            int k;
            scanf("%d", &k);
            printf("%d\n", sum(k));
        }
    }

    return 0;
}