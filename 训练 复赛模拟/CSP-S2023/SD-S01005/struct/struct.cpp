// rp++ Chtholly bless me

/*
  User:    RainPPR
  Problem: T3 struct
  Version: 1.0
  Exp:     20-40pts
*/

#include <bits/stdc++.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::unordered_map;
using std::string;
using std::pair;
using std::map;

using ll = long long;
using pll = pair<ll, ll>;

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

const int N = 110;

int n;
unordered_map<string, pll> to = {{"byte", {1, 1}}, {"short", {2, 2}}, {"int", {4, 4}}, {"long", {8, 8}}};

struct act {
	int op, cnt; ll add;
	string s, t;
	struct op1 {
		string tp, n;
	} p[N];
	// op1: s cnt []
	// op2: s t
	// op3: s
	// op4: add
} ac[N];

namespace no1 {
	map<string, ll> toa;
	map<ll, string> ton;
	void solve() {
		ll bt = 0;
		for (int t = 1; t <= n; ++t) {
			auto &now = ac[t];
			if (now.op == 2) {
				ll sz = to[now.s].first;
				ll st = ((bt + sz - 1) / sz) * sz;
				printf("%lld\n", st);
				toa[now.t] = st;
				ton[st + sz - 1] = now.t;
				bt = st + sz;
			} else if (now.op == 3) {
				printf("%lld\n", toa[now.s]);
			} else if (now.op == 4) {
				auto k = ton.lower_bound(now.add);
				if (k == ton.end()) printf("ERR\n");
				else {
					string name = k->second;
					if (now.add < toa[name]) printf("ERR\n");
					else printf("%s\n", name.c_str());
				}
			}
		}
	}
}

namespace only1 {
	void solve() {
		for (int t = 1; t <= n; ++t) {
			ll dq = 0, bt = 0;
			for (int i = 1; i <= ac[t].cnt; ++i) {
				pll sz = to[ac[t].p[i].tp];
				ll st = ((bt + sz.first - 1) / sz.first) * sz.first;
				cerr << i << ": " << st << endl;
				bt = st + sz.second, dq = max(dq, sz.first);
			} printf("%lld %lld\n", bt, dq);
			to[ac[t].s] = {dq, bt};
		}
	}
}

namespace Main {
	void solve() {
		while ((n -= 2) > 0) printf("ERR\n");
	}
}

signed main() {
	open("struct");
	fastio();
	cin >> n;
	bool isonly1 = true, isno1 = true;
	for (int i = 1; i <= n; ++i) {
		cin >> ac[i].op;
		if (ac[i].op == 1) {
			isno1 = false; cin >> ac[i].s >> ac[i].cnt;
			for (int j = 1; j <= ac[i].cnt; ++j) cin >> ac[i].p[j].tp >> ac[i].p[j].n;
		} else {
			isonly1 = false;
			if (ac[i].op == 2) cin >> ac[i].s >> ac[i].t;
			else if (ac[i].op == 3) cin >> ac[i].s;
			else if (ac[i].op == 4) cin >> ac[i].add;
		}
	} if (isno1) no1::solve();
	else if (isonly1) only1::solve();
	else Main::solve();
	return 0;
}
