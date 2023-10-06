#include <bits/stdc++.h>

using namespace std;

template<typename _Tp>
inline _Tp uread() {
	_Tp num = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
	return num;
}

using ll = long long;
const int N = 110;

ll a[N];

int in[N]; vector<int> g[N];
void add(int u, int v) { g[u].push_back(v); ++in[v]; }

int main() {
	int n = uread<int>();
	for (int i = 1; i <= n; ++i) a[i] = uread<ll>();
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (a[j] == a[i] * 2 || a[j] * 3 == a[i]) add(i, j);
	queue<int> q; vector<int> ans;
	for (int i = 1; i <= n; ++i) if (!in[i]) q.push(i), ans.push_back(i);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) if (--in[v] == 0) q.push(v), ans.push_back(v);
	} for (int i : ans) {
		printf("%lld ", a[i]);
	} return 0;
}

