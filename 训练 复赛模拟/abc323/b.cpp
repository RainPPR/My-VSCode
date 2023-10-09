#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> rk;
bool cmp(const pair<int, int> a, const pair<int, int> b) { return a.first == b.first ? a.second < b.second : a.first > b.first; }
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string l; cin >> l; rk.push_back({0, i + 1});
        for (int j = 0; j < n; ++j) if (l[j] == 'o') rk[i].first++;
    } sort(rk.begin(), rk.end(), cmp);
    for (pair<int, int> i : rk) printf("%d ", i.second);
    return 0;
}