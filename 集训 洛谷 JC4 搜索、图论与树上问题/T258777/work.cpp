#include <bits/stdc++.h>
using namespace std;

int n, q;
int dad[1005];

void input() {
    cin >> n >> q;
    for(int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        dad[u] = v;
    }
}

void work() {
    while(q--) {
        int x, y, ans=0;
        cin >> x >> y;

        while(y) {
            if(x == dad[y]) {
                ans = 1;
                break;
            }
            y = dad[y];
        }

        puts(ans ? "Yes" : "No");
    }
}

int main(void) {
    input();
    work();

    return 0;
}