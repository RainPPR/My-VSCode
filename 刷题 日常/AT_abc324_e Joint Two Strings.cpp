#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define open(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define smain signed main() { ios::sync_with_stdio(false); cin.tie(nullptr);
#define emain return 0; }

const int N = 5e5 + 10;

int l[N], r[N], w[N];

smain
    int k; string t;
    cin >> k >> t; int n = t.size();
    for (int i = 1; i <= k; ++i) {
        string s; cin >> s; int m = s.size();
        l[i] = r[i] = 0;
        for (int j = 0; j < m; ++j) if (l[i] < n && s[j] == t[l[i]]) ++l[i];
        for (int j = m - 1, q = n - 1; ~j; --j) if (~q && s[j] == t[q]) --q, ++r[i];
        ++w[l[i]];
    } for (int i = n - 1; ~i; --i) w[i] += w[i + 1];
    ll res = 0; for (int i = 1; i <= k; ++i) res += w[n - r[i]];
    printf("%lld\n", res);
emain
