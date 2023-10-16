#include <bits/stdc++.h>

using namespace std;

#define gd getdigitc()
inline char getdigitc() {
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    return ch;
}

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

#define gx(_) ((int)vector<float>({x - a, x - b, x + b, x + a})[_])
#define gy(_) ((int)vector<float>({y - b, y + a, y - a, y + b})[_])

using ll = long long;

const int N = 510;

int mp[N][N];
bitset<N> sl[N][N], sr[N][N], su[N][N], sd[N][N];

#define get(x, i, j) x[int(i)][int(j)]

int main() {
    int n = rr, op = rr; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mp[i][j] = gd - '0';
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) sl[i][j] = sl[i][j - 1] << 1, sl[i][j][0] = mp[i][j - 1], su[j][i] = su[j - 1][i] << 1, su[j][i][0] = mp[j - 1][i];
        for (int j = n - 2; ~j; --j) sr[i][j] = sr[i][j + 1] << 1, sr[i][j][0] = mp[i][j + 1], sd[j][i] = sd[j + 1][i] << 1, sd[j][i][0] = mp[j + 1][i];
    } ll res = 0; for (float x = 0.5; x + 0.5 <= n; x += 0.5) {
        float u1 = min(x, n - x - 1), dn = x == int(x) ? 1 : 0.5;
        for (float y = dn; y + 0.5 <= n; y += 1) {
            float u2 = min(y, n - y - 1), up = min(u1, u2);
            for (float b = dn; b <= up; b += 1) res += (get(sl, x + b, y + dn) & get(sr, x - b, y - dn) & get(su, x + dn, y - b) & get(sd, x - dn, y + b)).count();
        }
    } printf("%lld\n", res);
    return 0;
}
