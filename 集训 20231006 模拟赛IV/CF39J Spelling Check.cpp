#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string a, b;

using htp = unsigned long long;

const htp p1 = 47;
const htp p2 = 53;

htp ft1[N], ft2[N];

htp hb1, hb2;

htp ha1[N], ha2[N];
htp rha1[N], rha2[N];

pair<htp, htp> merge(htp lp1, htp lp2, htp rp1, htp rp2, int rsz) {
	htp h1, h2;
	h1 = lp1 * ft1[rsz] + rp1;
	h2 = lp2 * ft2[rsz] + rp2;
	return {h1, h2};
}

vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ft1[0] = ft2[0] = 1; for (int i = 1; i < N; ++i) ft1[i] = ft1[i - 1] * p1, ft2[i] = ft2[i - 1] * p2;
	cin >> a >> b; for (char c : b) hb1 = hb1 * p1 + c, hb2 = hb2 * p2 + c;
	for (int i = 1, j = a.size() - 1; i <= a.size(); ++i, --j) {
		ha1[i] = ha1[i - 1] * p1 + a[i - 1];
		ha2[i] = ha2[i - 1] * p2 + a[i - 1];
		rha1[i] = a[j] * ft1[i - 1] + rha1[i - 1];
		rha2[i] = a[j] * ft2[i - 1] + rha2[i - 1];
	} for (int i = 0, j = a.size() - 1; i < a.size(); ++i, --j) {
		pair<htp, htp> t = merge(ha1[i], ha2[i], rha1[j], rha2[j], j);
		if (t.first == hb1 && t.second == hb2) ans.push_back(i + 1);
	} printf("%d\n", ans.size());
	for (int i : ans)printf("%d ", i);
	return 0;
}
