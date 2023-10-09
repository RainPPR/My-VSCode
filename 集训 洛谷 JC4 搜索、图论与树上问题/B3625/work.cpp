#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[105][105];

void input() {
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i] + 1;
}

int vis[105][105];

const int dx[] = {+1, -1, 0, 0};
const int dy[] = {0, 0, +1, -1};

void dfs(int x, int y) {
    if(x < 1 || x > n) return;
    if(y < 1 || y > m) return;
    if(a[x][y] != '.') return;

    if(vis[x][y]) return;
    vis[x][y] = 1;

    for(int i=0; i<4; i++)
        dfs(x+dx[i], y+dy[i]);
}

void work() {
    dfs(1, 1);
    puts(vis[n][m] ? "Yes" : "No");
}

int main(void) {
    input();
    work();

    return 0;
}