#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e4 + 10;

int n, l;
int s[N];
int q[N], dp[N];

int Gx(int k1, int k2) { return (2 * s[k1]) - (2 * s[k2]); }
int Gy(int k1, int k2) { return (dp[k1] + s[k1] * s[k1] + 2 * l * s[k1]) - (dp[k2] + s[k2] * s[k2] + 2 * l * s[k2]); }
int Gv(int i, int j) { return dp[j] + (s[i] - s[j] - l) * (s[i] - s[j] - l); }

signed main() {
    scanf("%lld %lld", &n, &l); ++l;
    for (int i = 1; i <= n; ++i) { scanf("%lld", s + i); s[i] += s[i - 1] + 1; }
    int st = 0, ed = 1;
    for (int i = 1; i <= n; ++i) {
        while (st + 1 < ed && Gy(q[st + 1], q[st]) <= s[i] * Gx(q[st + 1], q[st])) ++st;
        dp[i] = Gv(i, q[st]);
        while (st + 1 < ed && Gx(q[ed - 1], q[ed - 2]) * Gy(i, q[ed - 1]) <= Gx(i, q[ed - 1]) * Gy(q[ed - 1], q[ed - 2])) --ed;
        q[ed++] = i;
    } printf("%lld\n", dp[n]);
    return 0;
}
