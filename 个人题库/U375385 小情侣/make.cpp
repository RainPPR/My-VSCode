#include <bits/extc++.h>
#include <windows.h>

using namespace std;

#define cmd(x) system(string(x).c_str())

#define open(x) ofstream fout(x)
#define close() fout.close()

#define endl ("\n")

using ll = long long;

int rd() {
    return (rand() << 15) | rand();
} int rd(int x) {
    return rd() % x;
} int rd(int l, int r) {
    return rd() % (r - l + 1) + l;
}

void solve(int T) {
    string name = "xql" + to_string(T);
    open(name + ".in");
    int n = rd(2e5, 2e6), m = rd(2e5, 2e6), p = rd(1e3, 2e8);
    fout << n << " " << m << " " << p << endl;
    for (int i = 1; i <= n; ++i) fout << rd(1e5, 1e8) << " \n"[i == n];
    for (int i = 1; i <= m; ++i) fout << rd(1e5, 1e8) << " \n"[i == n];
    close(); double a = clock();
    cmd("run<" + name + ".in>" + name + ".out");
    double b = clock(); cerr << b - a << " ms" << endl;
}

signed main() {
    srand(time(0) * clock());
    for (int T = 25; T <= 25; ++T) solve(T);
}
