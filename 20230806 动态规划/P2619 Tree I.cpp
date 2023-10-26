#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

const int N = 5e4 + 10;

int n, m, nd, ad;

struct point {
    int u, v, w, col;
    int cost() { return w + ad * (1 - col); }
    friend bool operator <(point &a, point &b) { int ac = a.cost(), bc = b.cost(); return ac == bc ? a.col < b.col : ac < bc; }
};

vector<point> g;
int f[N]; int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

pair<int, int> dijkstra() {
    sort(g.begin(), g.end()); int res = 0, cnt = 0;;
    for (int i = 0; i < n; ++i) f[i] = i;
    for (point i : g) {
        int x = find(i.u), y = find(i.v);
        if (x == y) continue;
        res += i.cost(); f[x] = y;
        cnt += 1 - i.col;
    } return {res, cnt};
}

int main() {
    n = rr, m = rr, nd = rr;
    for (int i = 1; i <= m; ++i) {
        int u = rr, v = rr, w = rr, col = rr;
        g.push_back({u, v, w, col});
    } int ans, l = -110, r = 110; while (l <= r) {
        ad = l + r >> 1; pair<int, int> ans0 = dijkstra();
        int a0 = ans0.first, k0 = ans0.second;
        if (k0 >= nd) l = ad + 1, ans = a0 - ad * nd;
        else r = ad - 1;
    } printf("%d\n", ans);
    return 0;
}
