#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 60;
const int MOD = 1e7 + 7;

int a[N];
int f[N][N];

int dfs(int pos, bool limit, int cnt)
{
    if (!pos)
        return max(cnt, 1ll);
    if (!limit && ~f[pos][cnt])
        return f[pos][cnt];

    int up = limit ? a[pos] : 1;

    int res = 1;
    for (int i = 0; i <= up; ++i)
        res = res * dfs(pos - 1, limit && i == up, cnt + i) % MOD;

    if (!limit)
        f[pos][cnt] = res;
    return res;
}

int solve(int x)
{
    int len = 0;
    while (x)
    {
        a[++len] = x & 1;
        x >>= 1;
    }
    return dfs(len, true, 0);
}

signed main()
{
    memset(f, -1, sizeof f);

    int n;
    scanf("%lld", &n);

    printf("%lld\n", solve(n));
    return 0;
}
