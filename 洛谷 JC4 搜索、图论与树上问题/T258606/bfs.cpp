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

void bfs(int x) {
    queue <int> q;
    q.push(x);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(vis[now]) continue;
        vis[now] = 1;

        for(auto p: edge[now])
            if(!vis[p])
                q.push(p);
    }
}

void work() {
    bfs(1);
    puts(vis[n] ? "Yes" : "No");
}

int main(void) {
    input();
    work();

    return 0;
}