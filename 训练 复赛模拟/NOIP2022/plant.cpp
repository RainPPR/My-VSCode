#include <bits/stdc++.h>

#define int long long
#define rr read()

#define m_debug 0

using namespace std;

const int MOD = 998244353;
const int N = 1010;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

inline char _readc()
{
    char ch = getchar();
#ifdef mdebug
    while (ch == '\n' || ch == '\r' || ch == ' ' || ch == '\t')
#else
    while (ch == '\n' || ch == ' ')
#endif
        ch = getchar();
    return ch;
}

int a[N][N];

int gor[N][N];
int iss[N][N];

int cntc[N][N];

int isc[N][N];
int cntf[N][N];

void solve()
{
    int n = rr, m = rr, c = rr, f = rr;

    int resc = 0, resf = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            a[i][j] = _readc() == '0';

        int res = 0;
        for (int j = m; j; --j)
        {
            if (a[i][j])
                gor[i][j] = ++res;
            else
                gor[i][j] = res = 0;

            if (!a[i][j])
            {
                iss[i][j] = cntc[i][j] = isc[i][j] = cntf[i][j] = 0;
                continue;
            }

            iss[i][j] = (a[i][j] && gor[i - 1][j] ? gor[i - 1][j] - 1 : 0) + iss[i - 1][j];
            cntc[i][j] = gor[i][j] ? (gor[i][j] - 1) * iss[i - 1][j] : 0;

            isc[i][j] = isc[i - 1][j] + cntc[i][j];
            cntf[i][j] = isc[i - 1][j];

            resc = (resc + cntc[i][j]) % MOD;
            resf = (resf + cntf[i][j]) % MOD;
        }
    }

#ifdef mdebug
    for (int i = 1; i <= n; ++i, fprintf(stderr, "\n"))
        for (int j = 1; j <= m; ++j)
            fprintf(stderr, "(%lld, %lld) ", cntc[i][j], cntf[i][j]);
#endif

    printf("%lld %lld\n", resc * c % MOD, resf * f % MOD);
}

signed main()
{
#ifndef mdebug
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);
#endif

    int T = rr, id = rr;
    while (T--)
        solve();

#ifndef mdebug
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
