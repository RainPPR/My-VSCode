#include <bits/stdc++.h>
using namespace std;
const int N = 5010, M = N * 10;
using bs = bitset<M>;
int mod2(string e) {
    return (e.back() - '0') & 1;
} string div2(string e) {
    string res; int x = 0;
    for (char c : e) {
        x = x * 10 + (c - '0');
        if (x >= 2) res.push_back(x / 2 + '0'), x %= 2;
        else if (res.size()) res.push_back('0');
    } return res;
} bs to2(string e) {
    bs res; int x = 0, p = 0;
    while (e.size()) {
        res[p++] = mod2(e); e = div2(e);
    } return res;
} signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string a, b; int k; cin >> a >> b >> k;
    bs a2 = to2(a), b2 = to2(b);
	printf((a2 ^ b2).count() == k ? "Yes\n" : "No\n");
	return 0;
}
