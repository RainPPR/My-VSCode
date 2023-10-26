#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string a, b;
string rsuba[N];

vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b;
	for (int i = 1, j = a.size() - 1; i <= a.size(); ++i, --j) {
		rsuba[i] = a[j] + rsuba[i - 1];
	} string suba;
	for (int i = 0; i < a.size(); ++i) {
		string t = suba + rsuba[a.size() - i - 1];
		cerr << rsuba[a.size() - i - 1] << " " << a.size() - i - 1 << endl;
		if (t == b) ans.push_back(i + 1);
		suba = suba + a[i];
	} printf("%d\n", ans.size());
	for (int i : ans) printf("%d ", i);
	return 0;
}
