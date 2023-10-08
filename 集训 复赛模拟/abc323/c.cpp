#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 110;
const int M = 110;

struct prb {
    int scr; bool isq[N];
    bool operator <(const prb &t) const { return scr > t.scr; }
} p[M];

int e[N], me;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> p[i].scr;
    for (int i = 1; i <= n; ++i) {
        string l; cin >> l; e[i] = i;
        for (int j = 0; j < m; ++j) if (l[j] == 'o') p[j + 1].isq[i] = 1, e[i] += p[j + 1].scr;
        if (e[i] > me) me = e[i];
    } sort(p + 1, p + 1 + m);
    for (int i = 1; i <= n; ++i) {
        int c = 0; for (int j = 1; e[i] < me && j <= m; ++j) if (!p[j].isq[i]) e[i] += p[j].scr, ++c;
        printf("%d\n", c);
    } return 0;
}