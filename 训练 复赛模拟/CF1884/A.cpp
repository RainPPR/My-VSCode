#include <bits/stdc++.h>

using namespace std;

int fun(int x) {
    string e = to_string(x);
    int res = 0; for (int i : e) {
        res += i - '0';
    } return res;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int x, k; scanf("%d %d", &x, &k);
        while (fun(x) % k != 0) ++x;
        printf("%d\n", x);
    } return 0;
}