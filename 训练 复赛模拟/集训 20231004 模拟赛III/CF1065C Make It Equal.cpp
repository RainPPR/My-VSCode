#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
	int num = 0, flag = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
	for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * flag;
}

const int H = 2e5 + 10;

int t[H];

int main() {
    int n = rr, k = rr;
    int r = 0, l = 1e9;
    for (int i = 1, h; i <= n; ++i) h = rr, r = max(r, h), l = min(l, h), ++t[h];
    for (int i = r - 1; i >= l; --i) t[i] += t[i + 1];
    int res = 0, sum = 0;
    for (int i = r; i >= l; --i) {
        if (sum + t[i] > k) sum = 0, ++res;
        sum += t[i];
    } if (sum > n) ++res;
    printf("%d\n", res);
    return 0;
}
