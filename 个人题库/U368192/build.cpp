#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace solve {
    const int N = 5010, M = N * 10;
    using bs = bitset<M>;
    int mod2(string e) {
        return (e.back() - '0') & 1;
    } string div2(string e) {
        string res; int x = 0;
        for (char c : e) {
            x = x * 10 + (c - '0');
            if (x >= 2) res.push_back(x / 2 + '0'), x %= 2;
            else if (res.size()) res.push_back('0');
        } return res;
    } bs to2(string e) {
        bs res; int x = 0, p = 0;
        while (e.size()) {
            res[p++] = mod2(e); e = div2(e);
        } return res;
    } int solve(string a, string b) {
        bs a2 = to2(a), b2 = to2(b);
        return (a2 ^ b2).count();
    }
}

ll land(ll p, int cnt = -1) {
    if (cnt == -1) cnt = rand() % 3 + 2;
    if (cnt == 1) return 1ll * rand() % p;
    if (cnt == 2) return 1ll * rand() * rand() % p;
    else if (cnt == 3) return 1ll * rand() * rand() * rand() % p;
    else return 1ll * rand() * rand() * rand() * rand() % p;
} string sand() {
    string a; int cp = land(500 - 20, 2) + 20;
    for (int i = 0; i < cp; ++i) a += to_string(land(1e10));
    return a;
}

int cmd(string x) {
    return system(x.c_str());
} signed main() {
    srand(clock() * time(0));
    for (int t = 36; t <= 50; ++t) {
        string filename = "bfe" + to_string(t);
        ofstream fout(filename + ".in");

        string a = sand(), b = sand();
        int k = solve::solve(a, b);

        int isright = land(2, 1);
        int sep = isright ? land(5, 1) - 2 : 0;

        cerr << sep << endl;
        fout << a << " " << b << " " << k + sep << endl;

        fout.close();
        cmd("s2.exe<" + filename + ".in>" + filename + ".out");
    }
	return 0;
}
