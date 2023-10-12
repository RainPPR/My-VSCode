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

const int N = 4010;

int n, res;
vector<int> g[N];

char col[N];
int sz[N], blk[N];

void dfs(int u) {
    sz[u] = 1, blk[u] = col[u] == 'B';
    for (int v : g[u]) {
        dfs(v); sz[u] += sz[v], blk[u] += blk[v];
    } res += (blk[u] << 1) == sz[u];
}

int main() {
    int T = rr;
    while (T--) {
        memset(col, 0, sizeof col);
        n = rr; for (int i = 2; i <= n; ++i) g[rr].push_back(i);
        scanf("%s", col + 1); res = 0;
        dfs(1); printf("%d\n", res);
        for (int i = 1; i <= n; ++i) g[i].clear();
    }
    return 0;
}
