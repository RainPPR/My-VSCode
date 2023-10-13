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

#define tp(t) template<typename t>

#define max _max
tp(t) inline t _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) inline t _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) inline t _abs(const t x) { return x < 0 ? -x : x; }

int main() {
    int T = rr; while (T--) {
        ;
    }
    return 0;
}
