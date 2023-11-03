#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

const int N = 1e7 + 10;
const int K = 1.7e6 + 10;

#define rr read()
inline int read() {
    int n = 0, f = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

bool have7(int x) {
    string t = to_string(x);
    for (char c : t) if (c == '7') return 1;
    return 0;
}

bool is[N]; int cnt;

vector<int> res;

void init() {
    res.resize(K); rep(i, N) {
        if (is[i]) continue;
        if (!have7(i)) res[cnt++] = i;
        else for (int j = i; j < N; j += i) is[j] = 1;
    }
}

int bnd(int x) {
    int l = 0, r = cnt;
    while (l < r) {
        int mid = l + r >> 1;
        if (res[mid] <= x) l = mid + 1;
        else r = mid;
    } return res[l];
}

int main() {
    init(); int T = rr;
    while (T--) {
        int x = rr;
        if (is[x]) printf("-1\n");
        else printf("%d\n", bnd(x));
    } return 0;
}
