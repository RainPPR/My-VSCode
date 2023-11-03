#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

signed main() {
    int n = rr, s = 0;
    vector<int> a(n);
    rep(i, n) a[i] = rr, s += a[i];
    if (s % n != 0) printf("-1\n"), exit(0);
    int per = s / n, l = 0, res = 0;
    gor(i, 1, n) l += a[i - 1], res += l != i * per;
    printf("%d\n", res);
    return 0;
}
