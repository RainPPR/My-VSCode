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

const int N = 310;

int n, m, k;
vector<int> a;

struct perf {
    vector<deque<int>> e;
    perf() { e.clear(); }
    perf(int t) { e.clear(); e.resize(t); }
    bool empty() {
        for (auto i : e) if (i.size()) return false;
        return true;
    }
    // front 定义为栈顶
    // back  定义为栈底
} q;

class result {
private:
    struct node { int op, s1, s2; };
public:
    vector<node> a;
    void print() {
        auto write = [] (node i) { i.op == 1 ? printf("1 %d\n", i.s1) : printf("2 %d %d\n", i.s1, i.s2); };
        printf("%d\n", (int)a.size());
        for_each(a.begin(), a.end(), write);
    }
} res;

bool dfs(int now) {
    if (res.a.size() > m + m) return false;
    auto bak = q; rep(i, n) if (q.e[i].size())
        rep(j, n) if (i != j && q.e[j].size() && q.e[i].back() == q.e[j].back()) {
            q.e[i].pop_back(), q.e[j].pop_back();
            res.a.push_back({2, i + 1, j + 1});
            if (dfs(now)) return true;
            res.a.pop_back(), q = bak;
    } if (now == m) return q.empty();
    rep(i, n) {
        if (q.e[i].size() && q.e[i].front() == a[now]) q.e[i].pop_front();
        else q.e[i].push_front(a[now]);
        res.a.push_back({1, i + 1, -1});
        if (dfs(now + 1)) return true;
        res.a.pop_back(), q = bak;
    } return false;
}

signed main() {
    auto input = [&] () { n = rr, m = rr, k = rr, a.resize(m), generate(a.begin(), a.end(), read); };
    auto init = [&] { q = perf(n), res.a.clear(); };
    auto solve = [&] () { q = perf(n); dfs(0); res.print(); };
    int T = rr; while (T--) {
        input(), init(), solve();
    } return 0;
}
