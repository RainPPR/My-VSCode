#include <bits/extc++.h>

using namespace std;

#define call(cmd) system(string(cmd).c_str())
#define open(file) ofstream fout(file)
#define close() fout.close()

const int N = 2e5 + 10;

int f[N];
void init(int n) {
    for (int i = 1; i <= n; ++i) f[i] = i;
} int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
} bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    f[find(x)] = find(y);
    return true;
}

int main() {
    srand(time(0) * clock());

    for (int K = 31; K <= 50; ++K) {

        double a = clock();
        open("bfs" + to_string(K) + ".in");

        int T = rand() % 100 + 1; fout << T << endl;
        for (int i = 1; i <= T; ++i) {
            int n = rand() % 199999 + 2; fout << n << endl;
            init(n); for (int j = 1; j < n; ++j) {
                int u = rand() % n + 1, v = rand() % n + 1;
                while (u == v) v = rand() % n + 1;
                if (!merge(u, v)) { --j; continue; }
                fout << u << " " << v << endl;
            }
        }
        
        close();
        double b = clock();

        cerr << "GEN: " << b - a << " ms" << endl;

        double c = clock();
        call("std<bfs" + to_string(K) + ".in>bfs" + to_string(K) + ".out");
        double d = clock();

        cerr << "RUN: " << d - c << " ms" << endl;
    }
    return 0;
}