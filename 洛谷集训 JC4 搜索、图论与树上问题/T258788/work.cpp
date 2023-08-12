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

        while(y) {
            if(x == dad[y]) {
                ans = 1;
                break;
            }
            y = dad[y];
        }

        puts(ans ? "Yes" : "No");
    }
}

int main(void) {
    input();
    work();

    return 0;
}