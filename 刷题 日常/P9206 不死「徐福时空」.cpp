#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)
#define gc() getchar()

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = n * 10 + c - '0';
    return f ? -n : n; 
}

inline void write(int x) {
    printf("%d ", x);
}

int n, m, res;
vector<int> a, d;

void solve(int k) {
    rep(i, n) {
        int t = i; ++res;
        while (t >= k && a[t] < a[t - k])
            swap(a[t], a[t - k]), t -= k, ++res;
    }
}

signed main() {
    n = rr, m = rr;
    a.resize(n), d.resize(m);
    generate(a.begin(), a.end(), read);
    generate(d.begin(), d.end(), read);
    for_each(d.begin(), d.end(), solve);
    printf("%d\n", res);
    for_each(a.begin(), a.end(), write);
    return 0;
}
