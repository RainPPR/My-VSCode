#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

using vi = vector<int>;

void print(vi &a, char sep = '\n') {
    cout << "{" << a[0];
    for (int i = 1; i < a.size(); ++i) cout << ", " << a[i];
    cout << "}" << sep;
}

void turn(vi &a) {
    reverse(a.begin(), a.end());
}

void move(vi &a) {
    int t = a.back();
    for (int i = a.size() - 1; i; --i) a[i] = a[i - 1];
    a[0] = t;
}

void iv(vi &a) {
    int n = a.size(); vi t(n);
    for (int i = 0; i < n; ++i) t[a[i] - 1] = i + 1;
    a = t;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vi a(n); rep(_, n) cin >> a[_];
    while (q--) {
        string s; int c; cin >> s >> c;
        while (c--) for (char op : s)
            if (op == 'S') move(a);
            else if (op == 'F') turn(a);
            else iv(a);
    } for (int _ : a) printf("%d ", _);
    return 0;
}
