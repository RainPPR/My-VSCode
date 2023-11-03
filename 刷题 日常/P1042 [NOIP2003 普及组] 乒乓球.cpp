#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

template<int k>
struct node {
    vector<pii> cpt;
    void clear() {
        cpt.clear();
    } node() {
        clear(); cpt.push_back({0, 0});
    } void add(char c) {
        auto &a = cpt.back().first, &b = cpt.back().second;
        if (c == 'W') ++a;
        else ++b;
        if (a < k && b < k) return;
        if (abs(a - b) < 2) return;
        cpt.push_back({0, 0});
    } void print() {
        for (pii i : cpt)
            printf("%d:%d\n", i.first, i.second);
    }
};

signed main() {
    node<11> a; node<21> b; int ch = getchar();
    while (ch != 'E') {
        while (ch != 'W' and ch != 'E' and ch != 'L') ch = getchar();
        if (ch == 'E') break;
        a.add(ch), b.add(ch), ch = getchar();
    } a.print(), putchar('\n'), b.print();
    return 0;
}
