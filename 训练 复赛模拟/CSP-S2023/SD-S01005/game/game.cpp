// rp++ Chtholly bless me

/*
  User:    RainPPR
  Problem: T2 game
  Version: 1.0
  Exp:     25pts
*/

#include <bits/stdc++.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::queue;
using std::set;
using std::vector;
using std::map;
using std::make_pair;

using pii = pair<int, int>;

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

int n;

namespace Main {
	queue<pii> q; map<pii, pii> res;
	map<int, vector<int>> inright, inleft;
	void solve() {
		string str;
		cin >> str;
		for (int i = 0, j = 1; j < str.size(); i = j, ++j) {
			if (str[i] == str[j]) q.push({i, j});
		} while (q.size()) {
			pii now = q.front(); q.pop();
			int l = now.first, r = now.second;
			pair<int, int> mt = make_pair(inright.count(r + 1) ? inright[r + 1].size() : 0, inleft.count(l - 1) ? inleft[l - 1].size() : 0);
			if (res.count(now) && res[now] == mt) continue; res[now] = mt;
			if (inright.count(r + 1)) for (int i : inright[r + 1]) q.push({l, i});
			if (inleft.count(l - 1))  for (int i : inleft[l - 1]) q.push({i, r});
			inright[l].push_back(r), inleft[r].push_back(l);
			for (int s = 1; ; ++s) {
				if (l - s < 0 || r + s >= n) break;
				if (str[l - s] != str[r + s]) break;
				q.push({l - s, r + s});
			}
		} printf("%d\n", (int)res.size());
	}
}

signed main() {
	open("game");
	fastio();
	cin >> n;
	// if (n == 1) printf("0\n");
	Main::solve();
	return 0;
}
