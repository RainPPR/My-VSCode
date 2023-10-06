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

const int N = 1e5 + 10;

int a[N]; // 原数组
int s[N]; // 前缀和
int m[N]; // 前缀和后缀最大值

int main() {
	int n = rr, d = rr;
	for (int i = 1; i <= n; ++i) {
		a[i] = rr; s[i] = s[i - 1] + a[i];
	} m[n] = s[n]; for (int i = n - 1; i; --i) {
		m[i] = max(m[i + 1], s[i]);
	} if (m[1] > d) printf("-1"), exit(0);
	int add = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		s[i] += add, m[i] += add;
		if (a[i] == 0 && s[i] < 0) {
			int cmin = -s[i], cmax = d - m[i];
			if (cmin > cmax) printf("-1"), exit(0);
			add += cmax, ++cnt;
		}
	} printf("%d\n", cnt);
	return 0;
}
