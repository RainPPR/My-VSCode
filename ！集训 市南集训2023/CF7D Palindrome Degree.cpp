#include <bits/stdc++.h>

using namespace std;

using hp = unsigned long long;

const int N = 5e6 + 10;

const hp P1 = 53, P2 = 97;
const hp M1 = 1e9 + 7, M2 = 1e9 + 9;

hp l1, r1, frac1 = 1;
hp l2, r2, frac2 = 1;

int dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string str; cin >> str;
    int res = 0; for (int i = 0; i < str.size(); ++i) {
        l1 = (l1 * P1 + str[i]) % M1, r1 = (r1 + str[i] * frac1) % M1, frac1 = frac1 * P1 % M1;
        l2 = (l2 * P2 + str[i]) % M2, r2 = (r2 + str[i] * frac2) % M2, frac2 = frac2 * P2 % M2;
        if (l1 == r1 && l2 == r2) res += (dp[i + 1] = dp[i + 1 >> 1] + 1);
    } printf("%d\n", res);
    return 0;
}
