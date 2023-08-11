#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10;

int n, m, s;
int w[N], v[N];

int ql[N], qr[N];
int s1[N], s2[N];

int gety(int W)
{
    for (int i = 1; i <= n; ++i)
        s1[i] = s1[i - 1] + (w[i] >= W), s2[i] = s2[i - 1] + (w[i] >= W) * v[i];

    int sum = 0;
    for (int i = 1; i <= m; ++i)
        sum += (s1[qr[i]] - s1[ql[i] - 1]) * (s2[qr[i]] - s2[ql[i] - 1]);
    return sum;
}

signed main()
{
    scanf("%lld %lld %lld", &n, &m, &s);

    for (int i = 1; i <= n; ++i)
        scanf("%lld %lld", w + i, v + i);
    for (int i = 1; i <= m; ++i)
        scanf("%lld %lld", ql + i, qr + i);

    int l = 0, r = 1e6;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (gety(mid) > s)
            l = mid;
        else
            r = mid;
    }

    printf("%lld\n", min(abs(gety(l) - s), abs(gety(r) - s)));
    return 0;
}