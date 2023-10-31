#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

inline string readstr() { string s; return (cin >> s, s); }
inline void writeint(int x, char sep = '\n') { cout << x << sep; }
void error() { cout << "-1" << endl, exit(0); }

unordered_map<string, vector<int>> arr;

int getnest(string name) {
    int op = 0; for (char c : name) op += c == '[';
    return op;
}

pair<string, string> split(string name) {
    char a[1010], b[1010];
    sscanf(name.c_str(), "%[^[][%s", a, b);
    string t = b; t.pop_back();
    return {a, t};
}

int query(string name) {
    if (getnest(name) == 0) return stoi(name);
    string a, b; int t; tie(a, b) = split(name);
    if ((t = query(b)) >= arr[a].size()) error();
    return arr[a][t];
}

void add(string name) {
    string a, b; tie(a, b) = split(name);
    arr[a].resize(query(b));
}

void modify(string name, string k) {
    string a, b; int t; tie(a, b) = split(name);
    if ((t = query(b)) >= arr[a].size()) error();
    arr[a][t] = query(k);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string op; while ((op = readstr(), op.size())) {
        if (op == "int") add(readstr());
        else if (op == "cout") writeint(query(readstr()));
        else modify(op, readstr());
    } return 0;
}
