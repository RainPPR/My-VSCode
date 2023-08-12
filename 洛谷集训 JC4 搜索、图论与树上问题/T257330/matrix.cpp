#include <bits/stdc++.h>
using namespace std;

int w[1005][1005];
// w[x][y]: x,y 的好感度

int n, m;

void input() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        w[u][v] = x;
        w[v][u] = x;
    }
}

void work() {
    for(int x=1; x<=n; x++) {
        int cnt = 0;
        for(int i=1; i<=n; i++)
            cnt+=w[x][i];
        printf("%d\n", cnt);
    }
}

int main(void) {
    input();
    work();

    return 0;
}