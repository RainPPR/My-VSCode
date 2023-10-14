#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max _max
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

using ll = long long;

const int N = 510;

char mp[N][N];

int main() {
    freopen("firstsnow.in", "r", stdin);
    freopen("firstsnow.out", "w", stdout);
    int n = rr, tp = rr;
    for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (mp[i][j] == '0') continue;
            for (int l = 0; l < j && l <= n - i; ++l) {
                for (int d = max(1, max(1 + l - j, 1 - l - i)); d <= n - i - l && d <= n - j; ++d) {
                    if (mp[i + d][j - l] == '0') continue;
                    if (mp[i + l][j + d] == '0') continue;
                    if (mp[i + d + l][j - l + d] == '0') continue;
                    ++res;
                }
            }
        }
    } printf("%lld\n", res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
