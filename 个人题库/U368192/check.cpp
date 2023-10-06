#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll land(ll p, int cnt = -1) {
    if (cnt == -1) cnt = rand() % 3 + 2;
    if (cnt == 2) return 1ll * rand() * rand() % p;
    else if (cnt == 3) return 1ll * rand() * rand() * rand() % p;
    else return 1ll * rand() * rand() * rand() * rand() % p;
} int cmd(string x) {
    return system(x.c_str());
} signed main() {
    srand(clock() * time(0));
    // subtask 1-3
    while (1) {
        ofstream fout("in.txt");
        ll a = land(1e18 - 10, 4) + 10, b = land(1e18 - 10, 4) + 10, k = land(1e18, 3);
        fout << a << " " << b << " " << k << endl;
        cmd("s1.exe<in.txt>o1.txt"), cmd("s2.exe<in.txt>o2.txt");
        if (cmd("fc o1.txt o2.txt /n")) printf("WA\n"), exit(0);
        printf("AC\n");
    }
	return 0;
}
