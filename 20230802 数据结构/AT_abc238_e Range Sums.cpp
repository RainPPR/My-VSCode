#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int f[N];

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int a, int b)
{
    f[find(a)] = find(b);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; ++i)
        f[i] = i;

    int l, r;
    while (q--)
    {
        scanf("%d %d", &l, &r);
        merge(r, l - 1);
    }

    printf(find(n) == find(0) ? "Yes\n" : "No\n");
    return 0;
}