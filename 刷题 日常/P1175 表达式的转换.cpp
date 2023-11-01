#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

int n; string s;

string init(string t) {
    if (t[0] == '-') t[0] == 'Z';
    gor(i, 1, n) if (t[i] == '-' && t[i - 1] == '(') t[i] = 'Z';
    return t;
}

tuple<int, int, int> countin(int l, int r) {
    int a = 0, b = 0, c = 0, in = 0;
    gor(i, l, r) {
        if (s[i] == '(') ++in;
        else if (s[i] == ')') --in;
        if (in != 0) continue;
        if (s[i] == '+' || s[i] == '-') ++a;
        else if (s[i] == '*' || s[i] == '/') ++b;
        else if (s[i] == '^') ++c;
    } return make_tuple(a, b, c);
}

void build(int l, int r) {
    ;
}

signed main() {
    cin >> s;
    // n = s.size();
    // int a, b, c;
    // tie(a, b, c) = countin(0, n);
    // cerr << a << " " << b << " " << c << endl;
    // build(0, n);
    return 0;
}