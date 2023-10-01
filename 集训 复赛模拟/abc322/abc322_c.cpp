#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // the first fw & before
    cin >> a[1];
    for (int i = a[1] - 1; i; --i) s[i] = s[i + 1] + 1;
    // until the last fw
    for (int i = 2; i <= m; ++i) {
        cin >> a[i];
        for (int j = a[i] - 1; j > a[i - 1]; --j) s[j] = s[j + 1] + 1;
    } for (int i = 1; i <= n; ++i) printf("%d\n", s[i]);
    return 0;
}
