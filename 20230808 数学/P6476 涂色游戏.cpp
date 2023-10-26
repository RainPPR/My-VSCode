#include <bits/stdc++.h>

#define ur uread()

using namespace std;

unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

int gcd(int a, int b) {
    while (b != 0) tie(a, b) = make_tuple(b, a % b);
    return a;
}

signed main() {
    int T = ur; while (T--) {
        int p1 = ur, p2 = ur, k = ur; if (p1 > p2) tie(p1, p2) = make_tuple(p2, p1);
        if (k == 1) { printf("No\n"); continue; }
        int g = gcd(p1, p2); p1 /= g, p2 /= g;
        if (p2 < 2) { printf("Yes\n"); continue; }
        int r = (p2 - 2) / p1 + 1; printf(r >= k ? "No\n" : "Yes\n");
    }
    return 0;
}
