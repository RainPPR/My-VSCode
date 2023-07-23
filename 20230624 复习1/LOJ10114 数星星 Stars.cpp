#include <bits/stdc++.h>

using namespace std;

const int N = 32010;

int a[N];
int ans[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int t)
{
    for (int i = x; i <= N; i += lowbit(i))
        a[i] += t;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += a[i];
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        ++x;
        ans[sum(x)]++;
        add(x, 1);
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
