#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
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

multiset<int> dl, dr;

bool check() {
    if (dl.size() <= 1) return 0;
    return *dr.begin() < *dl.rbegin();
}

signed main() {
    // freopen("in.txt", "r", stdin);
    int q = rr; while (q--) {
        char op; scanf("%c", &op);
        int l = rr, r = rr;
        if (op == '+') dl.insert(l), dr.insert(r);
        else dl.erase(dl.find(l)), dr.erase(dr.find(r));
        printf(check() ? "YES\n" : "NO\n");
    } return 0;
}
