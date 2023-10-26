#include <bits/stdc++.h>
using namespace std;

vector <int> edge[100005];
// edge[x]: 存储 x 相连的点
// edge[x][0] edge[x][1] edge[x][2] ...

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

void work() {
    for(int x=1; x<=n; x++) {
        int cnt = 0;
        printf("%d\n", edge[x].size());
    }
}

int main(void) {
    input();
    work();

    return 0;
}