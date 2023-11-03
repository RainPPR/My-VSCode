#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

signed main() {
    int w = rr, n = rr;
    multiset<int> a;
    rep(i, n) a.emplace(rr);
    int cnt = 0;
    while (a.size() > 1) {
        int k = *a.begin(), t = w - k;
        a.erase(a.begin()), ++cnt;
        auto q = a.upper_bound(t);
        if (q != a.begin()) --q, a.erase(a.find(*q));
    } printf("%d\n", cnt + (int)a.size());
    return 0;
}
