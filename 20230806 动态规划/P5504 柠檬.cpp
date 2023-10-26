#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define stack _st
class _st {
private:
    vector<int> node;
public:
    void push(int x) { node.push_back(x); }
    int top() { return node.back(); }
    void pop() { node.pop_back(); }
    size_t size() { return node.size(); }
    bool empty() { return node.size() == 0; }
    int operator [](const int &t) const { return node[t]; }
};

#define ur uread()
inline unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

const int N = 1e5 + 10;
const int M = 1e4 + 10;

int s[N];
int c[N], fr[M];

ll f[N];
stack st[M];

inline ll y(const int j) { return f[j - 1] + 1ll * s[j] * c[j] * c[j] - 2ll * s[j] * c[j] + s[j]; }
inline ll k(const int i) { return 2ll * s[i] * c[i]; }
inline ll x(const int j) { return c[j]; }

inline double slope(const int l, const int r) { return 1.0 * (y(r) - y(l)) / (x(r) - x(l)); }

inline ll r(const int i, const int j) { return f[j - 1] + 1ll * s[i] * (c[i] - c[j] + 1) * (c[i] - c[j] + 1); }

#define t1 st[t].top()
#define t2 st[t][st[t].size() - 2]

signed main() {
    int n = ur;
    for (int i = 1; i <= n; ++i) c[i] = ++fr[s[i] = ur];

//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= i; ++j) {
//            if (s[i] != s[j]) continue;
//            f[i] = max(f[i], f[j - 1] + 1ll * s[i] * (c[i] - c[j] + 1) * (c[i] - c[j] + 1));
//        }
//    }

    for (int i = 1; i <= n; ++i) {
        int t = s[i];
        while (st[t].size() >= 2 && slope(t1, i) >= slope(t2, t1)) st[t].pop();
        st[t].push(i);
        while (st[t].size() >= 2 && slope(t2, t1) <= k(i)) st[t].pop();
        f[i] = r(i, t1);
    }

    printf("%lld\n", f[n]);
    return 0;
}

