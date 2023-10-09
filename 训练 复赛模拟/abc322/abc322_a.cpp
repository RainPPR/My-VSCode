#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; string str;
    cin >> n >> str;
    for (int i = 0; i < n - 2; ++i)
        if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
            printf("%d\n", i + 1), exit(0);
    printf("-1\n");
    return 0;
}
