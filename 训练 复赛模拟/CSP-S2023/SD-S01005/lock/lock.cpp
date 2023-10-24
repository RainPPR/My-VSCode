// rp++ Chtholly bless me

/*
  User:    RainPPR
  Problem: T1 lock
  Version: 1.0
  Exp:     100pts
*/

#include <bits/stdc++.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::vector;
using std::map;

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

const int N = 10;

int n;

namespace s1 {
	void solve() {
		printf("81\n");
	}
}

namespace s2 {
	vector<int> arr[N];
	map<vector<int>, int> cnt;
	int run(const int x) {
		if (x < 9) return x + 1;
		else return 0;
	} void solve() {
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 5; ++j) arr[i].push_back(rr(int));
			vector<int> tmp;
			for (int pos = 0; pos < 5; ++pos) {
				tmp = arr[i];
				for (int step = 1; step <= 9; ++step) {
					tmp[pos] = run(tmp[pos]);
					++cnt[tmp];
				}
			} for (int pos = 0; pos < 4; ++pos) {
				tmp = arr[i];
				for (int step = 1; step <= 9; ++step) {
					tmp[pos] = run(tmp[pos]), tmp[pos + 1] = run(tmp[pos + 1]);
					++cnt[tmp];
				}
			}
		} int res = 0;
		for (auto i : cnt) {
			if (i.second == n) ++res;
		} printf("%d\n", res);
	}
}

signed main() {
	open("lock");
	// fastio();
	n = rr(int);
	if (n == 1) s1::solve();
	else s2::solve();
	return 0;
}
