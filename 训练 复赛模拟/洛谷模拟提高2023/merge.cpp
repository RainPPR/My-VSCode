#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const ll INF64 = 4e18;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max(a, b) _max(a, b)
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min(a, b) _min(a, b)
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs(x) _abs(x)
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int N = 5e5 + 10;

int n;
vector<int> a;

struct op { int i, j, k; };

struct _res {
    op t[N]; int cnt;
    void clear() { cnt = 0; }
    int size() { return cnt; }
    void push_back(op x) { t[cnt++] = x; }
    void pop_back() { --cnt; }
    void print() { printf("%d\n", cnt); for (int i = 0; i < cnt; ++i) printf("%d %d %d\n", t[i].i, t[i].j, t[i].k); }
} res;

map<vector<int>, bool> mem;

bool dfs(vector<int> &now) {
    if (mem.count(now)) return mem[now];
    int nn = now.size() - 1;
    if (nn == 1) return mem[now] = true;
    if (nn == 2) return mem[now] = false;
    if (res.size() >= n) return mem[now] = false;
    if (nn == 3) {
        if ((now[1] ^ now[2] ^ now[3]) == 0) { res.push_back({1, 2, 3}); return mem[now] = true; }
        else return mem[now] = false;
    } if (nn == 4) {
        if ((now[1] ^ now[2] ^ now[4]) == 0) { res.push_back({1, 2, 4}); return mem[now] = true; }
        else if ((now[1] ^ now[3] ^ now[4]) == 0) { res.push_back({1, 3, 4}); return mem[now] = true; }
        else return mem[now] = false;
    } vector<int> xr(now); for (int i = 1; i < xr.size(); ++i) xr[i] ^= xr[i - 1];
    vector<int> le, re; le.push_back(0);
    for (int i = 1; i <= nn - 2; ++i) {
        re.clear(); for (int j = nn; j >= i + 2; --j) {
            for (int k = i + 1; k <= j - 1; ++k) {
                if (now[i] ^ now[j] ^ now[k]) continue;
                res.push_back({i, k, j});
                if (i) le.push_back(xr[j] ^ xr[i - 1]);
                else le.push_back(xr[j]);
                for (int i = re.size() - 1; ~i; --i) le.push_back(re[i]);
                if (dfs(le)) return mem[now] = true;
                for (int i = re.size(); ~i; --i) le.pop_back();
                res.pop_back();
            } re.push_back(now[j]);
        } le.push_back(now[i]);
    } return mem[now] = false;
}

signed main() {
    int T = rr; while (T--) {
        mem.clear(); a.clear(); a.push_back(0);
        n = rr; for (int i = 1; i <= n; ++i) a.push_back(rr);
        if (n == 1) printf("Huoyu\n0\n");
        else if (n == 2) printf("Shuiniao\n");
        else if (n == 3) {
            if ((a[1] ^ a[2] ^ a[3]) == 0) printf("Huoyu\n1\n1 2 3\n");
            else printf("Shuiniao\n");
        } else if (n == 4) {
            if ((a[1] ^ a[2] ^ a[4]) == 0) printf("Huoyu\n1\n1 2 4\n");
            else if ((a[1] ^ a[3] ^ a[4]) == 0) printf("Huoyu\n1\n1 3 4\n");
            else printf("Shuiniao\n");
        } else {
            res.clear();
            if (!dfs(a)) printf("Shuiniao\n");
            else printf("Huoyu\n", res.size()), res.print();
        }
    } return 0;
}
