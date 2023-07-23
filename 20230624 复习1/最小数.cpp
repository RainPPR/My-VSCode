#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int n;
int a[N];

int ans[N];
int s[N], top;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    memset(ans, -1, sizeof ans);

    for (int i = n - 1; i >= 0; --i)
    {
        while (top && a[i] < a[s[top]])
            ans[s[top--]] = a[i];
        s[++top] = i;
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    return 0;
}
