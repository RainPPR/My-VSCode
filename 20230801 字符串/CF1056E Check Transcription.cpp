// RainPPR
// 20230819183940

#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

const int N = 1e6 + 10;
const ull p = 1e9 + 7;
const ull mod = 1e9 + 9;

string t, s;

ull h[N];
ull pw[N];

int get(int l, int len)
{
    if (!l)
        return h[l + len - 1];
    return (h[l + len - 1] - h[l - 1] * pw[len] % mod + mod) % mod;
}

bool check(const int &l0, const int &l1)
{
    ull r0 = 0, r1 = 0;
    bool u0 = true, u1 = true;
    for (int i = 0, j = 0; i < t.size(); ++i)
    {
        if (t[i] == '0')
        {
            ull r = get(j, l0);
            if (u0)
                r0 = r, u0 = false;
            else if (r != r0)
                return false;
            j += l0;
        }
        else
        {
            ull r = get(j, l1);
            if (u1)
                r1 = r, u1 = false;
            else if (r != r1)
                return false;
            j += l1;
        }
    }
    return r0 != r1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> s;

    h[0] = s[0];
    for (int i = 1; i < s.size(); ++i)
        h[i] = (h[i - 1] * p + s[i]) % mod;

    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = (pw[i - 1] * p) % mod;

    int cnt0 = 0;
    for (char i : t)
        cnt0 += i == '0';
    int cnt1 = t.size() - cnt0;

    int l0_max = (s.size() - cnt1) / cnt0;

    int res = 0;
    for (int l0 = 1; l0 <= l0_max; ++l0)
    {
        int all0 = l0 * cnt0;
        int all1 = s.size() - all0;
        if (all1 % cnt1)
            continue;
        res += check(l0, all1 / cnt1);
    }

    cout << res << endl;
    return 0;
}