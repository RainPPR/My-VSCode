#include <bits/stdc++.h>

using namespace std;

const int N = (1e6 + 10) * 2;

int a[N], s[N];
int q[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%d", &t);
        a[i + n] = a[i] = t;
    }

    int m = n * 2 - 1;
    for (int i = 1; i <= m; ++i)
        s[i] = s[i - 1] + a[i];

    int ans = 0;
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i)
    {
        while (l <= r && i - q[l] >= n)
            ++l;
        while (l <= r && s[i] < s[q[r]])
            --r;
        q[++r] = i;

        if (i >= n && s[q[l]] - s[i - n] >= 0)
            ++ans;
    }

    printf("%d\n", ans);
    return 0;
}
