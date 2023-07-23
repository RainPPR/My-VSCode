#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], s[N];
int stk[N], top;

int ls[N], rs[N];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
    }

    a[++n] = 0, s[n] = s[n - 1];

    top = 0;
    for (int i = n; i >= 1; --i)
    {
        while (top && a[i] < a[stk[top]])
            ls[stk[top]] = i, --top;
        stk[++top] = i;
    }

    top = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (top && a[i] < a[stk[top]])
            rs[stk[top]] = i, --top;
        stk[++top] = i;
    }

    ls[1] = 1, rs[n] = n;

    long long ans = -2e9;
    for (int i = 1; i <= n; ++i)
    {
        long long hp = (long long)a[i] * (s[rs[i] - 1] - s[ls[i]]);
        ans = max(ans, hp);
    }

    printf("%lld\n", ans);
    return 0;
}