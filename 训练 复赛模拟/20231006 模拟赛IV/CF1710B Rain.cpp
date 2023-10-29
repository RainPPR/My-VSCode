#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
#define rr read()
inline int read() {
	int num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}
 
const int N = 2e5 + 10;
const int INF = 1e9;
 
int n, m;
ll x[N], p[N];
 
map<ll, ll> delt;
 
signed main() {
    int T = rr; while (T--) {
        delt.clear(); n = rr, m = rr;
        for (int i = 1; i <= n; ++i) {
            x[i] = rr, p[i] = rr;
            delt[x[i] - p[i] + 1] += 1;
            delt[x[i] + 1] -= 2;
            delt[x[i] + p[i] + 1] += 1;
        } ll b1 = -INF, b2 = -INF, ad = 0, adt = 0, lt;
        for (pair<ll, ll> i : delt) {
            adt += ad * (i.first - lt);
            if (adt > m) b1 = max(b1, adt - i.first + 1), b2 = max(b2, adt + i.first - 1);
            ad += i.second, lt = i.first;
        } for (int i = 1; i <= n; ++i) {
            putchar('0' + (p[i] + m - x[i] >= b1 && p[i] + m + x[i] >= b2));
        } putchar('\n');
    } return 0;
}