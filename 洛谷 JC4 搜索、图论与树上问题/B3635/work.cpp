#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    cin >> n;
}

struct PointInfo {
    int to, dis;        // to: 到哪个点；dis: 从 0 到 to 的距离
};

bool vis[1000005];

void bfs() {
    queue <PointInfo> q;
    q.push({0, 0});

    while(!q.empty()) {
        int now = q.front().to, curDis=q.front().dis;
        q.pop();

        if(now > n) continue;       // 防越界

        if(vis[now]) continue;      // 防重复访问
        vis[now] = 1;

        // printf("bfs %d: distance = %d\n", now, curDis);

        if(now == n) {
            printf("%d\n", curDis);
            return;
        }

        q.push({now+1, curDis+1});
        q.push({now+5, curDis+1});
        q.push({now+11, curDis+1});
    }

}

void work() {
    bfs();
}

int main() {
    input();
    work();

    return 0;
}