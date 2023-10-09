#include <bits/stdc++.h>
using namespace std;

int w[1005][1005];
vector <int> edge[1005];

int n, m;

void input() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        w[u][v] = 1;
        w[v][u] = 1;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

void work() {
    for(int i=1; i<=n; i++, puts(""))
        for(int j=1; j<=n; j++)
            printf("%d ", w[i][j]);
    
    for(int x=1; x<=n; x++) {
        sort(edge[x].begin(), edge[x].end());
        printf("%d ", edge[x].size());

        for(int p: edge[x])
            printf("%d ", p);
        puts("");
    }
}

int main(void) {
    input();
    work();

    return 0;
}