#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline signed read() {
	signed num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

#define rl readline()
inline string readline() {
	string res; char ch = getchar();
	while (ch == '\n' || ch == '\r') ch = getchar();
	while (ch != '\n' && ch != '\r') res.push_back(ch), ch = getchar();
	return res;
}

const int N = 4e5 + 10;

int n, q;
string a;

int nt(int u, int x) {
	if (x == 0) return u + u == n || u == n ? -1 : u + 1;
	if (x == 1) return u == 1 || u == n + 1 ? -1 : u - 1;
	if (x == 2) return u <= n ? -1 : u - n;
	else return u > n ? -1 : u + n;
}

int vis[N];

int solve(int u, int v) {
	memset(vis, 0, sizeof vis);
	queue<pair<int, int>> q; q.push({u, 0}); vis[u] = 1;
	while (q.size()) {
		pair<int, int> now = q.front(); q.pop();
		if (now.first == v) return now.second;
		for (int i = 0; i < 4; ++i) {
			int t = nt(now.first, i); if (t == -1 || vis[t] || a[t] == 'X') continue;
			// cerr << now.first << " - " << t << endl;
			q.push({t, now.second + 1}); vis[t] = 1;
		}
	} return -1;
}

int main() {
	n = rr, q = rr;
	a = " " + rl; a += rl;
	cerr << a << endl;
	while (q--) printf("%d\n", solve(rr, rr));
	return 0;
}
