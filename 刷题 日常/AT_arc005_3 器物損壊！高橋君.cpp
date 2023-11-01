#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

#define yes() printf("YES\n"), exit(0)
#define no() printf("NO\n"), exit(0)

const int N = 510;

const int INF = 1e9;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

vector<string> g;

struct node { int x, y, c; };

int vis[N][N];

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    g.resize(n); rep(i, n) cin >> g[i];
    node st, ed;
    rep(i, n) rep(j, m) {
        vis[i][j] = INF;
        if (g[i][j] == 's') st = {i, j, 0};
        if (g[i][j] == 'g') ed = {i, j, 0};
    } deque<node> q; q.push_front(st);
    while (q.size()) {
        node now = q.front(); q.pop_front();
        if (now.x == ed.x && now.y == ed.y) yes();
        rep(k, 4) {
            int x = now.x + dx[k], y = now.y + dy[k];
            if (x < 0 || x >= n) continue;
            if (y < 0 || y >= m) continue;
            if (now.c + (g[x][y] == '#') > 2) continue;
            int pass = now.c + (g[x][y] == '#');
            if (vis[x][y] <= pass) continue;
            vis[x][y] = pass;
            if (pass == 0) q.push_front({x, y, pass});
            else q.push_back({x, y, pass});
        }
    } no();
}
