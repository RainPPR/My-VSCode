#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    for (int i = 1; i < 16; i += 2) if (s[i] == '1') printf("No\n"), exit(0);
    printf("Yes\n"); return 0;
}