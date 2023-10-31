#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pil = pair<int, ll>;
using vil = vector<pil>;

#define endl '\n'
#define rep(i, n) for (int i = 0; i < (n); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

vil mean(vi &x) {
    vil ret[2]; ret[0].push_back({0, 0});
    int k = 0; rep(i, x.size()) {
        ret[k ^= 1].clear(); for (auto t : ret[k ^ 1])
        ret[k].push_back({t.first + x[i], t.second | (1 << i)}), ret[k].push_back({t.first - x[i], t.second});
    } sort(ret[k].begin(), ret[k].end());
    return ret[k];
}

ll solve(vi &a, int x) {
    int n = a.size();
    vi L, R; rep(i, n) (i < n / 2 ? L : R).push_back(a[i]);
    vil l = mean(L), r = mean(R);
    for (int i = 0, j = r.size() - 1; i < l.size(); ++i) {
        while (j >= 0 && l[i].first + r[j].first > x) --j;
        if (j < 0) break;
        if (l[i].first + r[j].first == x) return l[i].second | (r[j].second << n / 2);
    } printf("No\n"), exit(0);
}

signed main() {
    int N = rr, X = rr, Y = rr; vi x, y;
    rep(i, N) (i & 1 ? x : y).push_back(rr);
    ll a = solve(x, X), b = solve(y, Y);
    printf("Yes\n");
    int d = 1; rep(i, N) {
        if (i & 1) putchar(((a >> i / 2) & 1) == d ? 'R' : 'L'), d = ((a >> (i >> 1)) & 1);
        else putchar(((b >> i / 2) & 1) == d ? 'L' : 'R'), d = ((b >> (i >> 1)) & 1);
    } return 0;
}
