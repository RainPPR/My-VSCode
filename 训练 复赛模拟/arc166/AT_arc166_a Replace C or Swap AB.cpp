#include <bits/stdc++.h>

using namespace std;

int n;

struct node {
    string str; int cnt_a, cnt_b;
    void input() {
        cin >> str; cnt_a = cnt_b = 0;
        for (char i : str) cnt_a += i == 'A', cnt_b += i == 'B';
    } void input(string _str) {
        str = _str; cnt_a = cnt_b = 0;
        for (char i : str) cnt_a += i == 'A', cnt_b += i == 'B';
    }
};

bool check(const string &at, const string &bt) {
    node _a, _b; _a.input(at), _b.input(bt);
    if (_a.cnt_a > _b.cnt_a || _a.cnt_b > _b.cnt_b) return false;
    int ad_a = _b.cnt_a - _a.cnt_a, ad_b = _b.cnt_b - _a.cnt_b, pos = 0;
    while (ad_a) if (_a.str[pos] == 'C') _a.str[pos] = 'A', --ad_a; else ++pos;
    while (ad_b) if (_a.str[pos] == 'C') _a.str[pos] = 'B', --ad_b; else ++pos;
    string &a = _a.str, &b = _b.str;
    int ca = 0, cb = 0; for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 'C') ca = cb = 0;
        else ca += a[i] == 'A', cb += b[i] == 'A';
        if (ca < cb) return false;
    } return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T; while (T--) {
        string a, b; cin >> n >> a >> b;
        a.push_back('C'), b.push_back('C');
        string at, bt; bool flag = true;
        for (int i = 0; i <= n; ++i) {
            if (a[i] != 'C' && b[i] == 'C') { flag = false; break; }
            else if (a[i] == 'C' && b[i] == 'C') {
                if (!check(at, bt)) { flag = false; break; } else at = bt = "";
            } else at.push_back(a[i]), bt.push_back(b[i]);
        } printf(flag ? "Yes\n" : "No\n");
    } return 0;
}