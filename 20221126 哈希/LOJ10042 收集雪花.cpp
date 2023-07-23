#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int X = 1e9 + 10;

int a[N];
unordered_map<int, int> h;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    int ans = 1;
    int l = 0, r = 0;
    while (r < n)
    {
        ++h[a[r]];
        while (h[a[r]] > 1)
            --h[a[l]], ++l;

        ans = max(ans, r - l + 1);
        ++r;
    }

    printf("%d\n", ans);
    return 0;
}
