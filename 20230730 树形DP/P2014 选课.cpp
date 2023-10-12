#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

#define max _max
inline int _max(const int a, const int b) { return a > b ? a : b; }
#define min _min
inline int _min(const int a, const int b) { return a < b ? a : b; }

using ll = long long;

const int N = 310;
const int M = 310;

int n, m;
int s[N]; vector<int> g[N];

int f[N][M];
int dfs(int u) {
    int sz = 1; f[u][1] = s[u];
    for (int v : g[u]) {
        int up = dfs(v);
        for (int i = min(sz, m + 1); i; --i)
            for (int j = 1; j <= up && i + j <= m + 1; ++j)
                f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j]);
        sz += up;
    } return sz;
}

int main() {
    n = rr, m = rr;
    for (int i = 1; i <= n; ++i) {
        int k = rr; s[i] = rr;
        g[k].push_back(i);
    } dfs(0);
    printf("%d\n", f[0][m + 1]);
    return 0;
}
