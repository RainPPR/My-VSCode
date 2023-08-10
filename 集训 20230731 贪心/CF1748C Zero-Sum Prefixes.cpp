#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10;

int a[N];
int s[N];

signed main()
{
    int T;
    scanf("%lld", &T);

    while (T--)
    {
        int n;
        scanf("%lld", &n);

        vector<int> zp;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", a + i);
            if (a[i] == 0)
                zp.push_back(i);
        }

        int ans = 0;

        zp.push_back(n + 1);
        for (int i = 1; i < zp[0]; ++i)
        {
            s[i] = s[i - 1] + a[i];
            if (s[i] == 0)
                ++ans;
        }

        s[zp[0]] = s[zp[0] - 1];

        for (int i = 1; i < zp.size(); ++i)
        {
            int l = zp[i - 1], r = zp[i] - 1;

            map<int, int> cnt;
            int mxc = 0, mxs = 0;
            for (int j = l; j <= r; ++j)
            {
                s[j] = s[j - 1] + a[j];
                if (++cnt[s[j]] > mxc)
                    mxc = cnt[s[j]], mxs = s[j];
            }
            ans += mxc;
            s[zp[i]] = s[zp[i] - 1] - mxs;
        }

        printf("%lld\n", ans);
    }

    return 0;
}