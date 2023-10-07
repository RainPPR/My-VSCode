#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
string slwr(string str) {
    for (char &c : str) if (c >= 'A' && c <= 'Z') c += 32; return str;
} int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    string my = ouf.readToken();
    if (slwr(my) == "accepted") quitf(_ok, "The answer is correct.");
    else quitf(_wa, "The answer is wrong: expected = accepted, found = %s", slwr(my).c_str());
    return 0;
}