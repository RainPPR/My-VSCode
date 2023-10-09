#include <bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << endl
#define meow(args...) fprintf(stderr, args)

#define rr read()
#define ur uread()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

signed read() {
    signed num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

typedef pair<int, int> PII;

const int N = 21, M = 110;

int n, m, t[M];
int b1[M], b2[M], f1[M], f2[M];

int cuse(int s, int i) {
    if ((s & b1[i]) == b1[i] && (s & b2[i]) == 0) return (s & ~f1[i]) | f2[i];
    return -1;
}

int dis[1 << N];
bool st[1 << N];

int dijkstra(int s, int e) {
    memset(dis, 0x3f, sizeof dis); const int INF = dis[0];
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dis[s] = 0; heap.push({0, s});
    while (heap.size()) {
        int u = heap.top().second, d = heap.top().first, v; heap.pop();
        if (st[u]) continue; st[u] = true;
        for (int i = 0; i < m; ++i) {
            if ((v = cuse(u, i)) == -1) continue;
            if (dis[v] > d + t[i]) {
                dis[v] = d + t[i];
                heap.push({dis[v], v});
            }
        }
    } return dis[e] == INF ? 0 : dis[e];
}

signed main() {
    n = ur, m = ur; char b[N], f[N];
    for (int i = 0; i < m; ++i) {
        t[i] = ur; scanf("%s %s", b, f);
        for (int j = 0; j < n; ++j) {
            if (b[j] == '+') b1[i] |= 1 << j;
            else if (b[j] == '-') b2[i] |= 1 << j;
            if (f[j] == '-') f1[i] |= 1 << j;
            else if (f[j] == '+') f2[i] |= 1 << j;
        }
    } printf("%lld\n", dijkstra((1 << n) - 1, 0));
    return 0;
}
