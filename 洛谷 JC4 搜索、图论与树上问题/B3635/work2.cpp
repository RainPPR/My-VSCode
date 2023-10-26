#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    cin >> n;
}

int dis[1000005];

void work() {
    queue <int> q;
    q.push(0);

    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(now == n) {
            printf("%d", dis[now]);
            return;
        }

        if(dis[now] + 1 < dis[now+1])
            dis[now+1] = dis[now] + 1, q.push(now + 1);
        if(dis[now] + 1 < dis[now+5])
            dis[now+5] = dis[now] + 1, q.push(now + 5);
        if(dis[now] + 1 < dis[now+11])
            dis[now+11] = dis[now] + 1, q.push(now + 11);
    }
}

int main(void) {
    input();
    work();

    return 0;
}