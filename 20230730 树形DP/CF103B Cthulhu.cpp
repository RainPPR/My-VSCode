#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

#define max _max
inline int _max(const int a, const int b) { return a > b ? a : b; }
#define min _min
inline int _min(const int a, const int b) { return a < b ? a : b; }

const int N = 110;

/*int f[N], cnt;
inline int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
inline void merge(int p, int q) { p = find(p), q = find(q); if (p != q) f[p] = q, --cnt; }

int main() {
    int n = rr, m = rr;
    if (n != m) printf("NO\n"), exit(0);
    cnt = n; for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) merge(rr, rr);
    printf(cnt == 1 ? "FHTAGN!\n" : "NO\n");
    return 0;
}*/


int f[N], cnt;
inline int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
inline void merge(int p, int q) { p = find(p), q = find(q); p != q ? f[p] = q : ++cnt; }

int main() {
    int n = rr, m = rr;
    if (n != m) printf("NO\n"), exit(0);
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) merge(rr, rr);
    printf(cnt == 1 ? "FHTAGN!\n" : "NO\n");
    return 0;
}
