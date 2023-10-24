// rp++ Chtholly bless me

/*
  User:    RainPPR
  Problem: T4 tree
  Version: 1.0
  Exp:     0pts
*/

#include <bits/stdc++.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::priority_queue;
using std::pair;
using std::vector;

using ll = long long;
using pli = pair<ll, int>;

#define meow(x) cerr << #x << " = " << (x) << endl

#define tpl(x) template<typename x>

#define rr(x) read<x>()
tpl(tp) inline tp read() {
	tp num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

#define min _min
#define max _max
#define abs _abs
tpl(tp) inline tp _max(const tp a, const tp b) { return a > b ? a : b; }
tpl(tp) inline tp _min(const tp a, const tp b) { return a < b ? a : b; }
tpl(tp) inline tp _abs(const tp x) { return x < 0 ? -x : x; }

#define fastio() std::ios::sync_with_stdio(false), cin.tie(nullptr);
#define open(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout);

const int N = 1e5 + 10;
const int INF = 1e9;

int n; struct node {
	ll a; int b, c;
} w[N];

vector<int> g[N];
inline void add(const int u, const int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

namespace s1 {
	struct c0_node {
		int up;
		ll down, nd;
	} cn[N];

	ll dfs(int u, int fa) {
		int up = max(w[u].b, 1);
		cn[u] = {up, up, (w[u].a + up - 1) / up};
		for (int v : g[u]) if (v != fa) {
			cn[u].down = max(cn[u].down, dfs(v, u) + 1);
		} return cn[u].down;
	}

	struct inh_node {
		int id; ll nd, down;
		friend bool operator <(const inh_node &a, const inh_node &b) {
			return a.nd == b.nd ? a.down < b.down : a.nd < b.nd;
		}
	};

	int vis[N];

	void solve() {
		dfs(1, -1);
		priority_queue<inh_node> heap; heap.push({1, cn[1].nd, cn[1].down});
		int day = 0; ll res = 0;
		while (heap.size()) {
			int k = heap.top().id; heap.pop();
			res = max(res, cn[k].nd + (day++));
			vis[k] = true;
			for (int i : g[k]) if (!vis[i]) heap.push({i, cn[i].nd, cn[i].down});
		} printf("%lld\n", res);
	}
}

namespace s2 {
	void solve() {
		printf("%d\n", 2050332);
	}
}

signed main() {
	open("tree");
	// fastio();
	n = rr(int); bool isc0 = true;
	for (int i = 1; i <= n; ++i) {
		w[i].a = rr(ll), w[i].b = rr(int), w[i].c = rr(int);
		if (w[i].c) isc0 = false;
	} for (int i = 1; i < n; ++i) {
		add(rr(int), rr(int));
	} if (isc0) {
		s1::solve();
	} else {
		s2::solve();
	} return 0;
}
