#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

const int N = 90;
const int X = 2e7 + 20;

struct bag {
    vector<int> d; map<int, pii> f[N];
    void run(int x) {
        f[0][x] = {-1, 0}; for (int i = 0; i < d.size(); ++i)
        for (auto j : f[i]) f[i + 1][j.first + d[i]] = {j.first, 1}, f[i + 1][j.first - d[i]] = {j.first, -1};
    } vector<int> get(int x) {
        vector<int> res; for (int i = d.size(); i; --i) {
            if (!f[i].count(x)) printf("No\n"), exit(0);
            res.push_back(f[i][x].second), x = f[i][x].first;
        } return res;
    }
} go[2];

signed main() {
    int n = rr, x = rr, y = rr; for (int i = 1; i <= n; ++i) go[i & 1].d.push_back(rr);
    go[0].run(0), go[1].run(0); vector<int> a = go[0].get(x), b = go[1].get(y);
    printf("Yes\n"); int dir = 1;
    for (int k = 1, i = 0, j = 0; i < a.size() || j < b.size(); k ^= 1) {
        if (k == 1) {
            int tar = b[j++];
            // cerr << "K = 1: " << dir << " " << tar << endl;
            if (dir == 1 && tar == 1) putchar('L');
            else if (dir == 1 && tar == -1) putchar('R');
            else if (dir == -1 && tar == 1) putchar('R');
            else putchar('L');
            dir = tar;
        } else {
            int tar = a[i++];
            // cerr << "K = 0: " << dir << " " << tar << endl;
            if (dir == 1 && tar == 1) putchar('R');
            else if (dir == 1 && tar == -1) putchar('L');
            else if (dir == -1 && tar == 1) putchar('L');
            else putchar('R');
            dir = tar;
        }
    } return 0;
}
