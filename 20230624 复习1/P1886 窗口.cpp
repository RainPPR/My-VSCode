#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int a[N], ans[N];
int q[N], l, r;

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    l = 0, r = -1;
    for (int i = 0; i < n; ++i)
    {
        while (l <= r && i - q[l] >= k)
            ++l;
        while (l <= r && a[i] < a[q[r]])
            --r;
        q[++r] = i;
        if (i >= k - 1)
            printf("%d ", a[q[l]]);
    }
    putchar('\n');
    
    l = 0, r = -1;
    for (int i = 0; i < n; ++i)
    {
        while (l <= r && i - q[l] >= k)
            ++l;
        while (l <= r && a[i] > a[q[r]])
            --r;
        q[++r] = i;
        if (i >= k - 1)
            printf("%d ", a[q[l]]);
    }
    return 0;
}
