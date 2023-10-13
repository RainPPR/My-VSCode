#include <bits/extc++.h>
#include <windows.h>

using namespace std;

#define call(cmd) system(string(cmd).c_str())
#define open(file) ofstream fout(file)
#define close() fout.close()

int main() {
    srand(time(0) * clock());
    for (int T = 1; T <= 50; ) {
        cout << "--------------------" << endl;
        double k1 = clock();
        open("in.txt");
        int n = rand() % (5 * T) + 5;
        fout << n << endl; for (int i = 1; i <= n; ++i) {
            int c = rand() % (2 * T) + 10;
            int e = rand() % n + 1;
            if (i == e) { --i; continue; }
            fout << c << " " << e << endl;
        } close();
        double k2 = clock();
        cerr << "GEN: " << k2 - k1 << " ms" << endl;
        double a = clock();
        call("ac<in.txt>out1.txt");
        double b = clock();
        call("wa<in.txt>out2.txt");
        double c = clock();
        if (call("fc out1.txt out2.txt /n")) {
            cout << "WA!" << endl;
            call("copy in.txt in" + to_string(T) + ".in /a /b /y");
            call("copy out1.txt in" + to_string(T) + ".out /a /b /y");
            ++T;
        } else {
            cout << "AC~ " << b - a << " - " << c - b << endl;
        }
    } call("del /f in.txt");
    call("del /f out1.txt");
    call("del /f out2.txt");
    return 0;
}
