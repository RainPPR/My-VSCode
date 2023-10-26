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

template<typename tp, tp N>
class segment {
#define mid ((l + r) >> 1)
#define _v vector<tp>
private:
    int n; _v s, mad, mre;
    void _build(int k, int l, int r, _v &a) {
        if (l == r) { s[k] = a[l]; return; }
        _build(k * 2, l, mid, a), _build(k * 2 + 1, mid + 1, r, a);
        s[k] = max(s[k * 2], s[k * 2 + 1]);
    } void _pushdown(int k) {
        if (mre[k]) {
            s[k * 2] = s[k * 2 + 1] = mre[k * 2] = mre[k * 2 + 1] = mre[k];
            mad[k * 2] = mad[k * 2 + 1] = mre[k] = mad[k] = 0;
        } else if (mad[k]) {
            if (mre[k * 2]) mre[k * 2] += mad[k];
            else s[k * 2] += mad[k];
            if (mre[k * 2 + 1]) mre[k * 2 + 1] += mad[k];
            else s[k * 2 + 1] += mad[k];
            mad[k * 2] += mad[k], mad[k * 2 + 1] += mad[k];
            mad[k] = 0;
        }
    } void _add(int k, int l, int r, int p, int q, tp x) {
        if (r < p || l > q) return;
        if (l >= p && r <= q) { mad[k] += x; return; }
        _pushdown(k); _add(k * 2, l, mid, p, q, x), _add(k * 2 + 1, mid + 1, r, p, q, x);
        s[k] = max(s[k * 2], s[k * 2 + 1]);
    } void _modify(int k, int l, int r, int p, int q, tp x) {
        if (r < p || l > q) return;
        if (l >= p && r <= q) { mad[k] = 0, mre[k] = x; return; }
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
    void build(_v &a) {
        n = (int)a.size() - 1, s = mad = mre = _v(3 * n), _build(1, 1, n, a);
        cerr << "BUILD " << 1 << " " << n << endl;
    } void add(int l, int r, tp x) {
        cerr << "ADD " << l << " " << r << " : " << x << endl;
        _add(1, 1, n, l, r, x);
    } void modify(int l, int r, tp x) {
        cerr << "MODIFY " << l << " " << r << " : " << x << endl;
        _modify(1, 1, n, l, r, x);
    } tp query(int l, int r, int db = 1) {
        if (db) { int t = _query(1, 1, n, l, r); cerr << "QUERY " << l << " " << r << " | " << t << endl; return t; }
        else return _query(1, 1, n, l, r);
    }
#undef mid
#undef _v
};

const int N = 1e6 + 10;

segment<ll, N> sg;

signed main() {
    int n = rr, q = rr; vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) a[i] = rr;
    sg.build(a); while (q--) {
        cerr << "---------------" << endl;
        int op = rr, l = rr, r = rr;
        if (op == 1) sg.modify(l, r, rr);
        else if (op == 2) sg.add(l, r, rr);
        else printf("%lld\n", sg.query(l, r));
        cerr << "-DEBUG-" << endl;
        for (int i = 1; i <= n; ++i) fprintf(stderr, "%lld%c", sg.query(i, i, 0), " \n"[i == n]);
    } return 0;
}