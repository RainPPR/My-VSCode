#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define fec(i, p, x) for (auto i : p) if (i != x)

inline int readint() { int x; return (cin >> x, x); }
inline void writeint(int x, char sep = '\n') { cout << x << sep; }
inline string readstr() { string s; return (cin >> s, s); }
inline void writestr(string s, char sep = '\n') { cout << s << sep; }

const int N = 1010;
const int INF = 0x3f3f3f3f;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int use[3][256] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 4, 9, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
};

int n, m;
vector<string> a;

struct node {
    pii p; int s, fl;
    friend bool operator<(const node &_, const node &__) {
        return _.s == __.s ? _.fl > __.fl : _.s < __.s;
    } friend bool operator>(const node &_, const node &__) {
        return _.s == __.s ? _.fl < __.fl : _.s > __.s;
    }
};

vector<pii> go;

int lt[3];

int vis[N][N][3];
int dis[N][N][3];

int dijkstra(pii st, pii ed) {
    memset(dis, 0x3f, sizeof dis), memset(lt, 0x3f, sizeof lt);
    priority_queue<node, vector<node>, greater<node>> heap;
    heap.push({st, 0, 0}); while (heap.size()) {
        auto now = heap.top(); heap.pop();
        int x, y; tie(x, y) = now.p; if (now.p == ed) return now.s;
        if (vis[x][y][now.fl]) continue; else vis[x][y][now.fl] = 1;
        if (now.fl <= 0 && a[x][y] == '4') {
            if (dis[x][y][1] > now.s)
                dis[x][y][1] = now.s, heap.push({now.p, now.s, 1});
        } if (now.fl <= 1 && a[x][y] == '5') {
            if (dis[x][y][2] > now.s + 5)
                dis[x][y][2] = now.s + 5, heap.push({now.p, now.s + 5, 2});
        } if (a[x][y] == 'X' && lt[now.fl] > now.s) {
            lt[now.fl] = now.s;
            fec(i, go, now.p) if (dis[i.first][i.second][now.fl] > now.s + 1)
                dis[i.first][i.second][now.fl] = now.s + 1, heap.push({i, now.s + 1, now.fl});
        } rep(k, 4) {
            int i = x + dx[k], j = y + dy[k];
            if (i < 0 || j < 0 || i >= n || j >= m) continue;
            auto &u = use[now.fl][a[i][j]];
            if (u != -1 && dis[i][j][now.fl] > u + now.s)
                dis[i][j][now.fl] = u + now.s, heap.push({{i, j}, u + now.s, now.fl});
        }
    } return INF;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    n = readint(), m = readint(); pii st, ed;
    a.resize(n); rep(i, n) a[i] = readstr();
    rep(i, n) rep(j, m) switch (a[i][j]) {
        case 'S' : st = {i, j}; break;
        case 'E' : ed = {i, j}; break;
        case 'X' : go.push_back({i, j}); break;
        default: break;
    } int ans = dijkstra(st, ed); if (ans != INF) writeint(ans);
    else writestr("We want to live in the TouHou World forever\n");
    return 0;
}
