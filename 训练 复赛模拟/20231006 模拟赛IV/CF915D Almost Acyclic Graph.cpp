#include <bits/stdc++.h>

#define int long long

using namespace std;

#define rr(tp) read<tp>()
template<typename tp> inline tp read() {
    tp num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define min(a, b) _min(a, b)
template<typename tp> inline tp _min(const tp a, const tp b) { return a < b ? a : b; }
#define max(a, b) _max(a, b)
template<typename tp> inline tp _max(const tp a, const tp b) { return a > b ? a : b; }

const int N = 510;

int n, m, in[N];
vector<int> g[N];

int t[N];
bool top_sort(int del) {
    for (int i = 1; i <= n; ++i) t[i] = in[i] - (i == del);
    queue<int> q; for (int i = 1; i <= n; ++i) {
        if (!t[i]) q.push(i);
    } int res = 0; while (q.size()) {
        int u = q.front(); q.pop(); ++res;
        for (int v : g[u]) if (!--t[v]) q.push(v);
    } return res == n;
}

signed main() {
    n = rr(int), m = rr(int);
    for (int i = 1; i <= m; ++i) {
        int u = rr(int), v = rr(int);
        g[u].push_back(v), ++in[v];
    } if (top_sort(-1)) printf("YES\n"), exit(0);
    for (int i = 1; i <= n; ++i) if (in[i]) {
        if (top_sort(i)) printf("YES\n"), exit(0);
    } printf("NO\n");
    return 0;
}
