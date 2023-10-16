#include <bits/stdc++.h>

using namespace std;

#define inwin 0

#define ur uread()
inline int uread() {
    int num = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

#define rl readline()
inline string readline() {
    string str; int ch = getchar();
    #ifdef inwin
    while (ch == '\n' || ch == '\r') ch = getchar();
    while (ch != '\n' && ch != '\r') str.push_back(ch), ch = getchar();
    #else
    while (ch == '\n') ch = getchar();
    while (ch != '\n') str.push_back(ch), ch = getchar();
    #endif
    return str;
}

const int N = 2e5 + 10;

string str[N];

string tominstr(string str) {
    string str2 = str; reverse(str2.begin(), str2.end());
    if (str < str2) return str;
    else return str2;
}

inline bool cmp(const string a, const string b) {
    return (a + b) < (b + a);
}

signed main() {
    int n = ur; for (int i = 1; i <= n; ++i) str[i] = rl;
    sort(str + 1, str + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) printf("%s", str[i].c_str());
    putchar('\n');
    return 0;
}
