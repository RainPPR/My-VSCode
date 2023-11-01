#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

int n; string s;

void init() {
    if (s[0] == '-') s[0] = 'Z';
    gor(i, 1, n) if (s[i] == '-' && s[i - 1] == '(') s[i] = 'Z';
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

int finda(int l, int r) {
    for (int i = r - 1, in = 0; i >= l; --i) {
        if (s[i] == '(') ++in;
        else if (s[i] == ')') --in;
        if (in != 0) continue;
        if (s[i] == '+' || s[i] == '-') return i;
    } return -1;
}

int findb(int l, int r) {
    for (int i = r - 1, in = 0; i >= l; --i) {
        if (s[i] == '(') ++in;
        else if (s[i] == ')') --in;
        if (in != 0) continue;
        if (s[i] == '*' || s[i] == '/') return i;
    } return -1;
}

int findc(int l, int r) {
    for (int i = l, in = 0; i < r; ++i) {
        if (s[i] == '(') ++in;
        else if (s[i] == ')') --in;
        if (in != 0) continue;
        if (s[i] == '^') return i;
    } return -1;
}

vector<string> op;

void push(int l, int r) {
    string t = s.substr(l, r - l + 1);
    if (t[0] == 'Z') t[0] = '-';
    op.push_back(t);
}

void build(int l, int r) {
    if (l >= r) return;
    int a, b, c; tie(a, b, c) = countin(l, r);
    if (a == 0 && b == 0 && c == 0) {
        if (s[l] == '(' && s[r - 1] == ')') build(l + 1, r - 1);
        else push(l, r - 1);
    } else if (a == 0 && b == 0) {
        int p = findc(l, r);
        push(p, p), build(p + 1, r), build(l, p);
    } else if (a == 0) {
        int p = findb(l, r);
        push(p, p), build(p + 1, r), build(l, p);
    } else {
        int p = finda(l, r);
        push(p, p), build(p + 1, r), build(l, p);
    }
}

bool isoperator(string t) {
    return t == "+" || t == "-" || t == "*" || t == "/" || t == "^";
}

int run(int a, int b, string op) {
    switch (op[0]) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
        case '^' : return pow(a, b);
        default: throw "UNKNOWN OPERATOR";
    } return -1;
}

signed main() {
    cin >> s; n = s.size(); init();
    build(0, n); reverse(op.begin(), op.end());
    while (op.size() > 1) {
        for (string i : op) cout << i << " ";
        putchar('\n');
        auto t = op; op.clear();
        for (int i = 0, could = 1; i < t.size(); ++i)
            if (!isoperator(t[i]) || !could) op.push_back(t[i]);
            else {
                int b = stoi(op.back()); op.pop_back();
                int a = stoi(op.back()); op.pop_back();
                op.push_back(to_string(run(a, b, t[i])));
                could = 0;
            }
    } cout << op[0] << endl;
    return 0;
}
