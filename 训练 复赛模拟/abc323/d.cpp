#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline int read() {
    int n = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + c - '0';
    return n * f;
}

map<ll, ll> e;

int main() {
    int n = rr; for (int i = 1; i <= n; ++i) {
        int s = rr, c = rr; e[s] += c;
    } ll res = 0;
    for (auto i = e.begin(); i != e.end(); ++i) {
        ll s = i->first, c = i->second;
        if (c == 1) { ++res; continue; }
        res += c & 1; e[s << 1] += c >> 1;
    } printf("%lld\n", res);
    return 0;
}
