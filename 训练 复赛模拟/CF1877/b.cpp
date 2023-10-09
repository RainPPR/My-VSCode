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

const int N = 1e5 + 10;

using ll = long long;
using pii = pair<int, int>;

struct point {
    int a, b;
    friend bool operator<(const point &x, const point &y) {
        return x.b < y.b;
    }
} e[N];

int main() {
    int T = rr; while (T--) {
        int n = rr, p = rr;
        e[0] = {n, p};
        for (int i = 1; i <= n; ++i) e[i].a = rr;
        for (int i = 1; i <= n; ++i) e[i].b = rr;
        sort(e + 1, e + 1 + n);
        priority_queue<pii, vector<pii>, greater<pii>> heap; // 点权，下标
        heap.push({p, 0}); ll res = 0;
        int cnt = 0; while (cnt < n) {
            pair<int, int> now = heap.top();
            if (--e[now.second].a == 0) heap.pop();
            ++cnt; heap.push({e[cnt].b, cnt});
            res += now.first;
        } printf("%lld\n", res);
    } return 0;
}
