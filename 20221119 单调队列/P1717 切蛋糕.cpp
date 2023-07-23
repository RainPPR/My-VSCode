#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, k;
int a[N], s[N];

int q[N], l, r;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
    }

    int ans = -2e9;

    l = r = q[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (l <= r && i - q[l] > k)
            ++l;
        ans = max(ans, s[i] - s[q[l]]);
        while (l <= r && s[q[r]] >= s[i])
            --r;
        q[++r] = i;
    }

    printf("%d\n", ans);
    return 0;
}