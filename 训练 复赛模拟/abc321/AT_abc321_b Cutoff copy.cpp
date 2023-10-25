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

int main() {
    int n = rr, x = rr, sum = 0, l = 100, r = 0;
    vector<int> a; for (int i = 1; i < n; ++i) {
        int t = rr; a.push_back(t), sum += t;
        if (t < l) l = t; if (t > r) r = t;
    } if (sum - r >= x) printf("0\n"), exit(0);
    int nd = x - (sum - l - r); if (nd <= r) printf("%d\n", nd);
    else printf("-1\n"); return 0;
}
