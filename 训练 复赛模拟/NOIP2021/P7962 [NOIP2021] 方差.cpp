#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define rr read()
inline int read() {
    int n = 0, f = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

int n; ll ans;

ll calc(vector<int> &a) {
    ll r1 = 0, r2 = 0;
    for (int i : a) r1 += i * i, r2 += i;
    return n * r1 - r2 * r2;
}

int turn(vector<int> &a, int i) {
    return a[i - 1] + a[i + 1] - a[i];
}

constexpr double per = CLOCKS_PER_SEC;

void dfs(ll now, vector<int> a) {
    if (now < ans) ans = now;
    if (clock() > 0.9 * per) printf("%lld\n", ans), exit(0);
    for (int i = 1; i < a.size() - 1; ++i) {
        int t = a[i]; a[i] = turn(a, i);
        ll ed = calc(a);
        if (ed < now) dfs(ed, a);
        a[i] = t;
    }
}

int main() {
    vector<int> a;
    n = rr; a.resize(n);
    rep(i, n) a[i] = rr;
    ans = calc(a); dfs(ans, a);
    printf("%lld\n", ans);
    return 0;
}
