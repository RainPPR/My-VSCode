#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, w;
    Edge(int _to, int _w) {
        to=_to, w=_w;
    }
};

vector <Edge> edge[100005];

int n, m;

void input() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        edge[u].push_back(Edge(v, x));
    }
}

void work() {
    for(int x=1; x<=n; x++) {
        int cnt = 0;

        for(auto &e: edge[x])
            cnt += e.w;

        // for(int i=0; i<edge[x].size(); i++)
        //     cnt += edge[x][i].w;

        printf("%d\n", cnt);
    }
}

int main(void) {
    input();
    work();

    return 0;
}