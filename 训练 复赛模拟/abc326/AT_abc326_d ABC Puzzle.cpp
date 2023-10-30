#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

int n; string r, c; 
vvi ans;

void print(vvi &x) {
    for (auto i : x) {
        for (auto j : i) j == -1 ? putchar('.') : putchar('A' + j);
        putchar('\n');
    }
}

#define td(a, b, c, _a, _b, _c) (a) = (_a), (b) = (_b), (c) = (_c)

void dfs(int x, vb iscover, vb have[3]) {
    if (x == n) {
        printf("Yes\n");
        for (int sb = 0; sb < 3; ++sb)
            for (int t : have[sb]) if (!t) return;
        print(ans), exit(0);
    } int op1 = r[x], op2, op3;
    if (op1 == 'A') op2 = 'B', op3 = 'C';
    else if (op1 == 'B') op2 = 'A', op3 = 'C';
    else if (op1 == 'C') op2 = 'A', op3 = 'B';
    int sb1 = op1 - 'A', sb2 = op2 - 'A', sb3 = op3 - 'A';
    int t1, t2, t3;
    for (int i = 0; i < n - 2; ++i) {
        if (!iscover[i] && c[i] != op1) continue;
        if (have[sb1][i]) continue;
        for (int j = i + 1; j < n; ++j) {
            if (!iscover[j] && c[j] != op2) continue;
            if (have[sb2][j]) continue;
            for (int k = i + 1; k < n; ++k) {
                if (j == k) continue;
                if (!iscover[k] && c[k] != op3) continue;
                if (have[sb3][k]) continue;
                td(t1, t2, t3, iscover[i], iscover[j], iscover[k]);
                iscover[i] = iscover[j] = iscover[k] = 1;
                ans[x][i] = sb1, ans[x][j] = sb2, ans[x][k] = sb3;
                have[sb1][i] = have[sb2][j] = have[sb3][k] = 1;
                // fprintf(stderr, "= JOIN (%d, %c) (%d, %c) (%d, %c)\n", i, op1, j, op2, k, op3);
                dfs(x + 1, iscover, have);
                // fprintf(stderr, "= THROW (%d, %c) (%d, %c) (%d, %c)\n", i, op1, j, op2, k, op3);
                td(iscover[i], iscover[j], iscover[k], t1, t2, t3);
                ans[x][i] = -1, ans[x][j] = -1, ans[x][k] = -1;
                have[sb1][i] = have[sb2][j] = have[sb3][k] = 0;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> r >> c;
    rep(_, n) ans.push_back(vi(n, -1));
    vb x = vb(n); vb t[3] = {x, x, x};
    dfs(0, x, t); printf("No\n");
    return 0;
}
