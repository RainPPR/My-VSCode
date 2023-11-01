#include <bits/stdc++.h>

using namespace std;

using db = double;

vector<int> a2;

int gcd(int a, int b) {
    return abs(__gcd(a, b));
}

void write_float(int a, int b) {
    int t = gcd(a, b);
    a /= t, b /= t;
    printf("%d", a);
    if (b != 1) printf("/%d", b);
}

void write_sqrt(int a, int b) {
    if (a == 0) return;
    int c = 1;
    for (int i = a2.size() - 1; i; --i) if (a % a2[i] == 0) a /= a2[i], c *= i;
    int t = gcd(c, b);
    c /= t, b /= t;
    if (c != 1) printf("%d*", c);
    printf("sqrt(%d)", a);
    if (b != 1) printf("/%d", b);
}

bool isoversqrt(int x) {
    if (x == 0) return 0;
    return x / int(sqrt(x)) == sqrt(x);
}

void write(int a, int delta, int b) {
    if (delta < 0) printf("NO");
    else if (b < 0) write(-a, delta, -b);
    else if (isoversqrt(delta)) write(a + sqrt(delta), 0, b);
    else if (delta == 0 && a == 0) putchar('0');
    else if (delta == 0) write_float(a, b);
    else if (a == 0) write_sqrt(delta, b);
    else write_float(a, b), putchar('+'), write_sqrt(delta, b);
}

void solve(int a, int b, int c) {
    int delta = b * b - 4 * a * c;
    write(-b, delta, 2 * a);
    putchar('\n');
}

signed main() {
    for (int i = 0; i <= 4e4; ++i) a2.push_back(i * i);
    int T, M; cin >> T >> M;
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        solve(a, b, c);
    } return 0;
}
