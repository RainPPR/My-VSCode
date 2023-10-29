#include <bits/stdc++.h>
using namespace std;
inline long long qpow(long long a, int b) {
	long long r = 1; for (; b; b >>= 1) {
		if (b & 1) r = r * a;
		a = a * a;
	} return r;
} int main() {
	int n; cin >> n;
	if (n == 3) printf("24\n");
	else printf("%lld\n", 36ll * (n - 3) * qpow(4, n - 4) + 24ll * qpow(4, n - 3));
	return 0;
}
