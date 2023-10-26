// 一个比较强的线段树板子题
// P1253 扶苏的问题

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

template<typename tp, tp INIT>
class segment {
#define mid ((l + r) >> 1)
#define vp vector<tp>
private:
    int n; vp s, mad, mre;
    void _build(int k, int l, int r, vp &a) {
        if (l == r) { s[k] = a[l]; return; }
        _build(k * 2, l, mid, a), _build(k * 2 + 1, mid + 1, r, a);
        s[k] = max(s[k * 2], s[k * 2 + 1]);
    } void _addmad(int k, tp x) {
        s[k] += x;
        if (mad[k] == -INIT) mad[k] = x;
        else mad[k] += x;
    } void _addmre(int k, tp x) {
        s[k] = mre[k] = x, mad[k] = -INIT;
    } void _pushdown(int k) {
        if (mre[k] != -INIT) _addmre(k * 2, mre[k]), _addmre(k * 2 + 1, mre[k]), mre[k] = -INIT;
        if (mad[k] != -INIT) _addmad(k * 2, mad[k]), _addmad(k * 2 + 1, mad[k]), mad[k] = -INIT;
    } void _add(int k, int l, int r, int p, int q, tp x) {
        if (r < p || l > q) return;
        if (l >= p && r <= q) { _addmad(k, x); return; }
        _pushdown(k); _add(k * 2, l, mid, p, q, x), _add(k * 2 + 1, mid + 1, r, p, q, x);
        s[k] = max(s[k * 2], s[k * 2 + 1]);
    } void _modify(int k, int l, int r, int p, int q, tp x) {
        if (r < p || l > q) return;
        if (l >= p && r <= q) { _addmre(k, x); return; }
        _pushdown(k); _modify(k * 2, l, mid, p, q, x), _modify(k * 2 + 1, mid + 1, r, p, q, x);
        s[k] = max(s[k * 2], s[k * 2 + 1]);
    } tp _query(int k, int l, int r, int p, int q) {
        if (l >= p && r <= q) return s[k];
        _pushdown(k);
        if (mid < p) return _query(k * 2 + 1, mid + 1, r, p, q);
        if (mid >= q) return _query(k * 2, l, mid, p, q);
        return max(_query(k * 2 + 1, mid + 1, r, p, q), _query(k * 2, l, mid, p, q));
    }
public:
    void build(vp &a) {
        n = (int)a.size() - 1, s = mad = mre = vp(3 * n, -INIT), _build(1, 1, n, a);
    } void add(int l, int r, tp x) {
        _add(1, 1, n, l, r, x);
    } void modify(int l, int r, tp x) {
        _modify(1, 1, n, l, r, x);
    } tp query(int l, int r) {
        return _query(1, 1, n, l, r);
    }
#undef mid
#undef vp
};

const int N = 1e6 + 10;
const ll INF = 1e18;

signed main() {
    int n = rr, q = rr; vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) a[i] = rr;
    segment<ll, INF> sg;
    sg.build(a); while (q--) {
        int op = rr, l = rr, r = rr;
        if (op == 1) sg.modify(l, r, rr);
        else if (op == 2) sg.add(l, r, rr);
        else printf("%lld\n", sg.query(l, r));
    } return 0;
}
