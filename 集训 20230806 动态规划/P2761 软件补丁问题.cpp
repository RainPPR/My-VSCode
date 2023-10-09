#include <bits/stdc++.h>

#define gor(_Tp, x, s, t) for (_Tp x = s; x < t; ++x)
#define gore(_Tp, x, s, t) for (_Tp x = s; x <= t; ++x)
#define rgor(_Tp, x, s, t) for (_Tp x = s; x > t; --x)
#define rgore(_Tp, x, s, t) for (_Tp x = s; x >= t; --x)
#define _gor(_Tp, x, s, t, p) for (_Tp x = s; x < t; x += p)
#define _gore(_Tp, x, s, t, p) for (_Tp x = s; x <= t; x += p)
#define _rgor(_Tp, x, s, t, p) for (_Tp x = s; x > t; x -= p)
#define _rgore(_Tp, x, s, t, p) for (_Tp x = s; x >= t; x -= p)

#define debug(x) cerr << #x << " = " << x << endl
#define meow(args...) fprintf(stderr, args)

#define rr read()
#define ur uread()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 int128;
typedef unsigned __int128 uint128;

template<typename _Tp> _Tp _max(const _Tp a, const _Tp b) { return a > b ? a : b; }
template<typename _Tp> _Tp _min(const _Tp a, const _Tp b) { return a < b ? a : b; }
template<typename _Tp> _Tp _abs(const _Tp x) { return x < 0 ? -x : x; }

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

vector<PII> g[1 << N];
void add(int u, int v, int w) { g[u].push_back(make_pair(v, w)); }

int dis[1 << N];
bool st[1 << N];

int dijkstra(int s, int e) {
    memset(dis, 0x3f, sizeof dis); dis[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    while (heap.size()) {
        PII t = heap.top(); heap.pop();
        int d = t.first, u = t.second;
        if (st[u]) continue; st[u] = true;
        for (PII q : g[u]) {
            if (dis[q.first] > d + q.second) {
                dis[q.first] = d + q.second;
                heap.push({dis[q.first], q.first});
            }
        }
    } return dis[e] == 0x3f3f3f3f ? 0 : dis[e];
}

signed main() {
    int n = ur, m = ur;
    for (int i = 1; i <= m; ++i) {
        int t = ur, b1 = 0, b2 = 0, f1 = 0, f2 = 0;
        char b[N], f[N]; scanf("%s %s", b, f);
        for (int j = 0; j < n; ++j) {
            switch (b[j]) {
                case '+': b1 |= 1 << j; break;
                case '-': b2 |= 1 << j; break;
                default: break;
            } switch (f[j]) {
                case '-': f1 |= 1 << j; break;
                case '+': f2 |= 1 << j; break;
                default: break;
            }
        } for (int j = 0; j < (1 << n); ++j)
            if ((j & b1) == b1 && (j & b2) == 0) add(j, j & (~f1) | f2, t);
    } printf("%d\n", dijkstra((1 << n) - 1, 0));
    return 0;
}
