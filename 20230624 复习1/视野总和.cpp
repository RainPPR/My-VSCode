#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int ans;
int s[N], top;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    
    a[n++] = 2e9 + 10;

    for (int i = n - 1; i >= 0; --i)
    {
        while (top && a[i] >= s[top])
            ++ans, --top;
        s[++top] = a[i];
    }
    
    printf("%d\n", ans);
    return 0;
}
