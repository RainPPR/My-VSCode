#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
	int num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

const int N = 1e5 + 10;

int n, m, s;
bool out[N], flag;

vector<int> g[N];
bool vis[N][2], st[N];

int from[N][2];
void dfs(int u, int k) {
    flag |= st[u];
    if (vis[u][k]) return;
    st[u] = 1, vis[u][k] = 1;
    for (int v : g[u]) {
        if (!vis[v][k ^ 1]) from[v][k ^ 1] = u;
        dfs(v, k ^ 1);
    } st[u] = 0;
}

void print(int u, int k) {
    if (u == s && k == 1) printf("%d ", s);
    else print(from[u][k], k ^ 1), printf("%d ", u);
}

int main() {
    n = rr, m = rr;
    int c; for (int i = 1; i <= n; i++) {
        if (!(c = rr)) out[i] = 1;
        for (int j = 1; j <= c; j++) g[i].push_back(rr);
    } dfs(s = rr, 1);
    for (int i = 1; i <= n; i++) if (out[i] && vis[i][0]) {
        printf("Win\n"), print(i, 0), exit(0);
    } printf(flag ? "Draw\n" : "Lose\n");
    return 0;
}
