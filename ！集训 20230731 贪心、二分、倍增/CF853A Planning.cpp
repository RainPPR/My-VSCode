#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3e5 + 10;

int c[N];

int ans;
int res[N];

struct cmp
{
    bool operator()(const int &k1, const int &k2) const
    {
        return c[k1] < c[k2];
    }
};

signed main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);

    priority_queue<int, vector<int>, cmp> q;

    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", c + i);
        if (i <= k)
            q.push(i);
    }

    for (int i = k + 1; i <= k + n; ++i)
    {
        if (i <= n)
            q.push(i);
        res[q.top()] = i;
        ans += c[q.top()] * (i - q.top());
        q.pop();
    }

    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%lld ", res[i]);
    return 0;
}