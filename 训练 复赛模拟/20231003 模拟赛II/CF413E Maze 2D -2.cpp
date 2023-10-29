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
string a[2];

int solve(int l, int r) {
	int lt = l > n ? l - n : l, lrow = (l > n);
	int rt = r > n ? r - n : r, rrow = (r > n);
	if (lt == rt) return lrow != rrow;
	else if (lt > rt) swap(l, r), swap(lt, rt), swap(lrow, rrow);
	int res = 0;
	while (lt < rt) {
		if (a[lrow][lt + 1] == 'X') lrow = 1 - lrow, ++res;
		if (a[lrow][lt] == 'X') { return -1; }
		++lt, ++res;
	} if (lt != rt) return -1;
	return res + (lrow != rrow);
}

int main() {
	n = rr, q = rr;
	a[0] = " " + rl, a[1] = " " + rl;
	while (q--) printf("%d\n", solve(rr, rr));
	return 0;
}
