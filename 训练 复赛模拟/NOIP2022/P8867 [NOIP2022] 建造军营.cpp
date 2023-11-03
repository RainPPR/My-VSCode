#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;

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

const int MOD = 1e9 + 7;

#define ttp template<typename tp>

template<int m>
class modint {
private:
    ll value;
public:
    modint() { value = 0; }
    modint(int x) { value = x % m; }
    modint(ll x) { value = x % m; }
    ll get() { return value; }
    void print(char sep = '\n') { printf("%lld%c", value, sep); }
    ttp modint operator +(const tp v) { return modint((value + v) % m); }
    ttp modint operator +=(const tp v) { value = (value + v) % m; return *this; }
    ttp modint operator -(const tp v) { return modint((value - v + m) % m); }
    ttp modint operator -=(const tp v) { value = (value - v + m) % m; return *this; }
};

int n, m;
vector<pii> edge;

vector<int> f;
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

vector<int> inside;

unordered_map<int, int> check() {
    int cnt = 0; auto upcnt = [&] { return cnt++; };
    generate(f.begin(), f.end(), upcnt);
    set<int> inode;
    auto add = [&] (int k) {
        f[find(edge[k].first)] = f[find(edge[k].second)];
        inode.insert(edge[k].first), inode.insert(edge[k].second);
    }; for_each(inside.begin(), inside.end(), add);
    unordered_map<int, int> s;
    gor(i, 1, n + 1) ++s[find(i)];
    return s;
}

modint<MOD> ans;

void dfs(int k) {
    if (k == m) {
        if (inside.empty()) { ans += n; return; }
        auto qpow = [] (ll a, ll b, ll d) {
            ll r = 1;
            for (; b; b >>= 1, a = a * a % d) if (b & 1) r = r * a % d;
            return r;
        }; auto comb = [qpow] (ll x) {
            return qpow(2, x, MOD)-1;
        };
        auto p = check();
        modint<MOD> q;
        for (auto i : p) ans += comb(i.second), q += comb(i.second);
        for (int i : inside) cerr << i << ",";
        cerr << "\b: " << q.get() << endl;
        return;
    }
    inside.push_back(k);
    dfs(k + 1);
    inside.pop_back();
    dfs(k + 1);
}

signed main() {
    auto getedge = [&] { return make_pair(rr, rr); };
    n = rr, m = rr; f.resize(n + 1);
    edge.resize(m);
    generate(edge.begin(), edge.end(), getedge);
    dfs(0); printf("%lld\n", ans.get());
    return 0;
}
