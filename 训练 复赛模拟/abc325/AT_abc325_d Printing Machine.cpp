#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define rr(x) read<x>()
template<typename tp> inline tp read() {
    tp num = 0; int flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = (num << 1) + (num << 3) + ch - '0';
    return num * flag;
}

signed main() {
    int n = rr(int);
    vector<pll> node; for (int i = 0; i < n; ++i) {
        ll t = rr(ll), d = rr(ll); node.push_back({t, t + d});
    }sort(node.begin(), node.end());
    int it = 0, res = 0; priority_queue<ll, vector<ll>, greater<ll>> heap;
    for (ll now = 0; heap.size() || it < n; ++now) {
        if (heap.empty()) now = node[it].first;
        while (heap.size() && heap.top() < now) heap.pop();
        while (it < n && node[it].first == now) heap.push(node[it++].second);
        if (heap.size()) ++res, heap.pop();
    } printf("%d\n", res);
    return 0;
}
