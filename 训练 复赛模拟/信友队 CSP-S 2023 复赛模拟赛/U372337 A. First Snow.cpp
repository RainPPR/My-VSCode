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
bitset<N> l[N], r[N], u[N], d[N];

int main() {
    int n = rr, op = rr;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mp[i][j] = gd - '0';
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 1; j < n; ++j) l[j] = l[j - 1] << 1, l[j][0] = mp[i][j - 1], \
    //                                 u[j] = u[j - 1] << 1, u[j][0] = mp[j - 1][i];
    //     for (int j = n - 2; ~j; --j) r[j] = r[j + 1] << 1, r[j][0] = mp[i][j + 1], \
    //                                  d[j] = d[j + 1] << 1, d[j][0] = mp[j + 1][i];
    // }
    // (x-a,y-b) ... (x-b,y+a)
    //          (x,y)
    // (x+b,y-a) ... (x+a,y+b)
    ll res = 0;
    for (float x = 0.5; x + 0.5 <= n; x += 0.5) {
        bool isi = x == int(x);
        float dn = isi ? 1 : 0.5, u1 = min(x, n - x - 1);
        for (float y = dn; y + 0.5 <= n; y += 1) {
            float u2 = min(y, n - y - 1), up = min(u1, u2);
            if (isi) for (float b = dn; b <= up; b += 1) {
                int a = 0;
                if (mp[gx(0)][gy(0)] & mp[gx(1)][gy(1)] & mp[gx(2)][gy(2)] & mp[gx(3)][gy(3)]) ++res;
            } for (float a = dn; a <= up; a += 1) {
                for (float b = dn; b <= up; b += 1) {
                    if (mp[gx(0)][gy(0)] & mp[gx(1)][gy(1)] & mp[gx(2)][gy(2)] & mp[gx(3)][gy(3)]) ++res;
                }
            }
        }
    } printf("%lld\n", res);
    return 0;
}
