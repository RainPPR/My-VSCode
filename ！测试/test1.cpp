#include <bits/stdc++.h>

using namespace std;

const int N = 30;

struct matrix {
    int n, m, a[N][N];
    matrix operator *(const matrix t) const {
        matrix r = {n, t.m, {0}};
        for (int i = 0; i < n; ++i) for (int j = 0; j < t.m; ++j)
            for (int k = 0; k < m; ++k) r.a[i][j] = (r.a[i][j] + a[i][k] * t.a[k][j]) & 1;
        return r;
    }
};

int main()
{
    matrix t = {3, 3, {1, 0}};
    cout << t.n << endl;
    cout << t.m << endl;
    cout << t.a[0][0] << endl;
    cout << t.a[0][1] << endl;
    cout << t.a[1][2] << endl;
    return 0;
}