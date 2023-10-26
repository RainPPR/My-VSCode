#include <bits/stdc++.h>
using namespace std;

vector <int> edge[1005];

int n, q;
int dad[1005];

void input() {
    cin >> n >> q;
    for(int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}

// 建图
void dfs(int x) {
    static int vis[1005];
    vis[x] = 1;
    
    for(int p: edge[x])
        if(!vis[p]) {
            dad[p] = x;
            dfs(p);
        }
}

void work() {
    dfs(1);


    while(q--) {
        int x, y, ans=0;
        cin >> x >> y;

        // 问 x 是否有 y 这位直接下属

        for(int p: edge[x])
            if(p != dad[x])
                if(p == y) ans=1;

        puts(ans ? "Yes" : "No");
    }
}

int main(void) {
    input();
    work();

    return 0;
}