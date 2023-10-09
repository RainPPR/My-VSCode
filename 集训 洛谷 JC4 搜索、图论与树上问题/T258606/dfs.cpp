#include <bits/stdc++.h>
using namespace std;

vector <int> edge[100005];

int n, m;

void input() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

int vis[100005];

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = 1;

    for(int p: edge[x])
        dfs(p);
}

void work() {
    dfs(1);
    puts(vis[n] ? "Yes" : "No");
}

int main(void) {
    input();
    work();

    return 0;
}