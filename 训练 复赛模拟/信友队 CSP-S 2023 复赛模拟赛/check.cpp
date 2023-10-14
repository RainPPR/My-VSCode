#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <windows.h>

using namespace std;

#define cmd(x) system(string(x).c_str())

const string P = "firstsnow";
const int L = 1, R = 20;

signed main() {
    freopen("error.txt", "w", stderr);
    cmd("del /f /q ak.txt");
    for (int t = L; t <= R; ++t) {
        string k = to_string(t);

        string in = "sample\\" + P + k + ".in";
        cmd("copy /a /b /y " + in + " test.in");

        string ans = "sample\\" + P + k + ".ans";
        cmd("copy /a /b /y " + ans + " test.ans");

        double a = clock();
        cmd(P + "<test.in>test.out");
        double b = clock();

        if (cmd("fc test.out test.ans /n >> ak.txt")) cout << "WA!" << endl, cerr << "error: " << k << endl;
        else cout << "AC: " << b - a << " ms" << endl;
    } cmd("del /f /q test.in"), cmd("del /f /q test.ans"), cmd("del /f /q test.out");
    return 0;
}
