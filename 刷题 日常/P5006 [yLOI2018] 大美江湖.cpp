// P5006 [yLOI2018] ????

#include <bits/stdc++.h>

using namespace std;

inline int readint() { int x; cin >> x; return x; }
inline string readline() { string x; cin >> x; return x; }
inline void writeint(int x, char sep = '\n') { cout << x << sep; }

int n, m;
int hp0, st0, de0;
int x, y, hp, st, de;
vector<string> p;

int input() {
    n = readint(), m = readint();
    p.resize(n); for (auto &i : p) i = readline();
    hp0 = readint(), st0 = readint(), de0 = readint();
    x = readint() - 1, y = readint() - 1;
    hp = 0, st = readint(), de = readint();
    return readint();
}

void query() {
    writeint(hp, ' ');
    writeint(st, ' ');
    writeint(de);
}

int fight() {
    return max(1,
              (hp0 + max(1, st - de0) - 1) / max(1, st - de0)
                                           * max(1, st0 - de));
}

void run(int a, int b) {
    switch (p[a][b]) {
        case 'R': hp = max(hp - 10, 0); break;
        case 'Q': st += 5; break;
        case 'Y': de += 5; break;
        case 'M': hp += fight(); break;
    }
}

void move(int dir) {
    switch (dir) {
        case 1: --y; break;
        case 2: ++y; break;
        case 3: --x; break;
        case 4: ++x; break;
    } run(x, y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q = input();
    while (q--) {
        int op = readint();
        if (op == 1) query();
        else move(readint());
    } return 0;
}
