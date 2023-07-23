#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int lowbit(int x)
{
    return x & -x;
}

int n, m;
int al[N];
int ar[N];

void addl(int x)
{
    for (int i = x; i <= n; i += lowbit(i))
        ++al[i];
}
void addr(int x)
{
    for (int i = x; i <= n; i += lowbit(i))
        ++ar[i];
}

int getl(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += al[i];
    return res;
}
int getr(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += ar[i];
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i)
    {
        int k, l, r;
        scanf("%d %d %d", &k, &l, &r);

        if (k == 1)
            addl(l), addr(r);
        else
            printf("%d\n", getl(r) - getr(l - 1));
    }

    return 0;
}
