#include <bits/stdc++.h>

#define ur uread()

using namespace std;

unsigned uread() {
    unsigned num = 0; char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
    return num;
}

const int N = 1.5e5 + 10;
const int M = 390;

int arr[N];
int f[M][M];

signed main() {
    int n = ur, m = ur; int b = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        arr[i] = ur;
        for (int j = 1; j < b; ++j) f[j][i % j] += arr[i];
    } while (m--) {
        char op[2]; scanf("%s", op);
        int x = ur, y = ur; if (op[0] == 'C') {
            for (int i = 1; i < b; ++i) f[i][x % i] += y - arr[x];
            arr[x] = y;
        } else if (x < b) {
            printf("%d\n", f[x][y]);
        } else {
            int sum = 0; for (int i = y; i <= n; i += x) {
                sum += arr[i];
            } printf("%d\n", sum);
        }
    }
    return 0;
}
