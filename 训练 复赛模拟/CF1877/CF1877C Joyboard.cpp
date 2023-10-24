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

void solve() {
    int n = rr, m = rr, k = rr;
    if (k > 3) printf("0\n");
    else if (k == 1) printf("1\n");
    else if (k == 2) printf("%d\n", m > n ? n + (m - n) / n : m);
    else printf("%d\n", m > n ? m - n - (m - n) / n : 0);
}

int main() {
    int T = rr; while (T--) {
        solve();
    } return 0;
}
