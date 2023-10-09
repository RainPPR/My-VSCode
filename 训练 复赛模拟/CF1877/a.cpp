#include <bits/stdc++.h>

using namespace std;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

int main() {
    int T = rr; while (T--) {
        int n = rr, s = 0;
        for (int i = 1; i < n; ++i) s += rr;
        printf("%d\n", -s);
    } return 0;
}