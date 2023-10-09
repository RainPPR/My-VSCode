#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int n, h, r;

struct point {
    int x, y, z;

    point(int x=0, int y=0, int z=0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void input() {
        scanf("%d%d%d", &x, &y, &z);
    }

};

bool is_connected(point a, point b) {
    return (ll)(a.x - b.x) * (a.x - b.x)
            + (ll)(a.y - b.y) * (a.y - b.y)
            + (ll)(a.z - b.z) * (a.z - b.z) <= (ll)4 * r * r;
}

point p[1005];
vector <int> e[1005];   // e[i]: 与 i 点相连的点
bool visit[1005];

void init() {
    for(int i=0; i<=1003; i++)
        e[i].clear();
    memset(visit, 0, sizeof(visit));
}

void inp() {
    scanf("%d%d%d", &n, &h, &r);
    for(int i=1; i<=n; i++)
        p[i].input();
}

// 建图：若两个点联通，则给它们连边
void build_graph() {

    // 点编号 1~n 普通点
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(is_connected(p[i], p[j])) {
                // 若两个点联通，则在图上连边
                e[i].push_back(j);
                e[j].push_back(i);
            }
    
    // 0 超级起点
    for(int i=1; i<=n; i++)
        if(p[i].z <= r) e[0].push_back(i);

    // 1002 超级终点
    for(int i=1; i<=n; i++)
        if(p[i].z >= h - r) e[i].push_back(1002);
}

void bfs() {
    queue <int> q;
    int ans = 0;

    q.push(0);
    visit[0] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        // printf("visit %2d\n", now);

        if(now == 1002) ans = 1;

        for(int i=0; i<e[now].size(); i++) {
            int to = e[now][i];
            if(!visit[to]) {
                visit[to] = true;
                q.push(to);
            }
        }
    }

    puts(ans ? "Yes" : "No");
}

void work() {
    init();
    inp();
    build_graph();
    bfs();
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--)
        work();

    return 0;
}