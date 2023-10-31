#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

string gs() {
    string a;
    cin >> a;
    return a;
}

string gl() {
    string a;
    getline(cin, a);
    return a;
}

unordered_map<string, int> tea, stu;
unordered_set<string> play, over;
set<string> wan;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    rep(_, 3) tea.insert({gs(), _});
    rep(_, 5) stu.insert({gs(), _});
    while (n--) {
        string a = gs(), b = gl();
        if (b == " started playing games!" && stu.count(a)) play.insert(a);
        if (b == " stopped playing games!" && stu.count(a)) play.erase(a);
        if (b == " came!" && tea.count(a)) over.insert(a);
        if (b == " left!" && tea.count(a)) over.erase(a);
        if (over.empty()) continue;
        for (auto i : play) wan.insert(i);
    } for (auto i : wan) printf("%s ", i.c_str());
    if (wan.size() == 5) printf("\nHow Bad Oiers Are!\n");
    else if (wan.size() == 0) printf("How Good Oiers Are!\n");
    else putchar('\n');
    return 0;
}
