#include <bits/stdc++.h>

#define rr read()
#define min MIN

using namespace std;

typedef long long ll;

const int N = 110;
const ll MOD = 1e9 + 7;

inline ll read()
{
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

inline ll MIN(ll a, ll b) { return a < b ? a : b; }
inline ll MUL(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

int t, k, r;
int a[N], b[N];

ll dp[N][2][2];
ll dfs(int now, bool ln, bool lm)
{
    if (!now) return 1;
    if (dp[now][ln][lm] != -1) return dp[now][ln][lm];
    ll res = 0;
    int upn = ln ? a[now] : k - 1, upm = lm ? b[now] : k - 1;
    for (int i = 0; i <= upn; ++i) for (int j = 0; j <= i && j <= upm; ++j)
        res = (res + dfs(now - 1, ln && i == upn, lm && j == upm)) % MOD;
    return dp[now][ln][lm] = res;
}

int main()
{
    t = rr, k = rr;
    while (t--)
    {
        memset(dp, -1, sizeof dp);

        ll n = rr, m = min(n, rr);
        ll rt = (MUL(m + 1, m + 2) * 500000004ll % MOD + MUL(n - m, m + 1)) % MOD;

        int r = 0, ra = 0;
        while (n) a[++r] = n % k, n /= k;
        while (m) b[++ra] = m % k, m /= k;
        while (ra < r) b[++ra] = 0;

        printf("%lld\n", (rt - dfs(r, 1, 1) + MOD) % MOD);
    }
    return 0;
}
