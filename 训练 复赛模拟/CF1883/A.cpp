#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string tar; cin >> tar;
        int point = 1, res = 0;
        for (char ch : tar) {
            int q = ch - '0';
            if (q == 0) q = 10;
            res += abs(q - point) + 1;
            point = q;
        } printf("%d\n", res);
    } return 0;
}