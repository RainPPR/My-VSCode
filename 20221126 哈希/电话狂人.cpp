#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, int> cnt;

int main()
{
    int n;
    scanf("%d", &n);

    int mc = -1;
    long long a, b, ans;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld %lld", &a, &b);

        ++cnt[a];
        if (cnt[a] > mc || (cnt[a] == mc && a < ans))
            mc = cnt[a], ans = a;

        ++cnt[b];
        if (cnt[b] > mc || (cnt[b] == mc && b < ans))
            mc = cnt[b], ans = b;
    }

    printf("%lld %d\n", ans, mc);
    return 0;
}