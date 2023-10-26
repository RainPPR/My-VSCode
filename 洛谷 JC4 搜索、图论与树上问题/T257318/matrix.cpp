#include <bits/stdc++.h>
using namespace std;

int w[1005][1005];
// w[x][y]: x,y 是否为朋友

int n, m;

void input() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        w[u][v] = 1;
        w[v][u] = 1;
    }
}

void work() {
    for(int x=1; x<=n; x++) {
        int cnt = 0;
        for(int i=1; i<=n; i++)
            if(w[x][i]) cnt++;
        printf("%d\n", cnt);
    }
}

int main(void) {
    input();
    work();

    return 0;
}