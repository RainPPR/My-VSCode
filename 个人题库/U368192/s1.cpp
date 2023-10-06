#include <bits/stdc++.h>
using namespace std;
signed main() {
    long long a, b, e; int k, c;
    scanf("%lld %lld %d", &a, &b, &k);
    e = a ^ b, c = 0; while (e) e -= e & -e, ++c;
    printf(c == k ? "Yes\n" : "No\n");
    return 0;
}
