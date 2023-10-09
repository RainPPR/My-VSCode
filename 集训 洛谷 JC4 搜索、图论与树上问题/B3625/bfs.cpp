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

bool isValid(int x, int y) {
    if(x < 1 || x > n) return 0;
    if(y < 1 || y > m) return 0;
    return a[x][y] == '.';
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(vis[x][y]) continue;
        vis[x][y] = 1;

        for(int i=0; i<4; i++)
            if(isValid(x+dx[i], y+dy[i]))
                q.push(make_pair(x+dx[i], y+dy[i]));
    }
}

void work() {
    bfs(1, 1);
    puts(vis[n][m] ? "Yes" : "No");
}

int main(void) {
    input();
    work();

    return 0;
}