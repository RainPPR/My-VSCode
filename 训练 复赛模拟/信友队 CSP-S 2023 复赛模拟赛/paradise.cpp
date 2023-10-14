#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pli = pair<long long, int>;

#define rr read()
inline ll read() {
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max _max
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

#define open(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
#define close() fclose(stdin), fclose(stdout);

const int M = 1e5 + 10;

struct obj {
    ll a, b;
    ll up;
} o[M];

int main() {
    // open(a);
    int T = rr, op = rr;
    while (T--) {
        int m = rr, q = rr;
        // clear objects
        int idx = 0; for (int i = 1; i <= m; ++i) {
            ++idx, o[idx].a = rr, o[idx].b = rr;
            if (idx > 1 && (1.0 * o[idx].b / o[idx].a) >= (1.0 * o[idx - 1].b / o[idx - 1].a)) --idx;
        } m = idx;
        // calculate up to next
        o[m].up = 4e18; for (int i = 1; i < m; ++i) o[i].up = o[i + 1].a / o[i].a;
        // clear query
        vector<pli> e; for (int i = 0; i < q; ++i) e.push_back({rr, i});
        sort(e.begin(), e.end());
        // calculate
        idx = 0;
        // log error
        for (int i = 1; i <= m; ++i) printf("OBJ: %lld %lld %lld\n", o[i].a, o[i].b, o[i].up);
        for (int i = 0; i < q; ++i) printf("QUE: %lld %d\n", e[i].first, e[i].second);
        printf("\n");
    }
    // close();
    return 0;
}

// 对于商品，显然，我们要求 a 越大的，性价比越高且一定严格递增
// 一个部分分是，可以递推出来每个 n 是的情况
// 在上一个的情况下，多买一个 1 号，如果买到了 a2 个就舍弃 a1 买 a2；以此类推
