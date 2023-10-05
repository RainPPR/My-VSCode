#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rr read()
inline ll read() {
	ll num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

const int N = 2e5 + 10;

ll lst; map<int, int> c;
ll cnt, ans[N];

int main() {
	int n = rr; for (int i = 0; i < n; ++i) {
		++c[rr]; --c[rr + 1];
	} for (pair<ll, ll> i : c) {
		ans[cnt] += i.first - lst; lst = i.first; cnt += i.second;
	} for (int i = 1; i <= n; ++i) {
		printf("%lld ", ans[i]);
	} return 0;
}
