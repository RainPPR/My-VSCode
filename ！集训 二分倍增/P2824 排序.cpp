#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct que
{
    int op, l, r;
} query[N];

int a[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d %d %d", &query[i].op, &query[i].l, &query[i].r);

    int q;
    scanf("%d", &q);

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
    }
    return 0;
}