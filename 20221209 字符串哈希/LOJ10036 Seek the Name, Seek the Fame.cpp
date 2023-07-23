#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
const int N = 4e5 + 10;

unsigned long long fact[N];
unsigned long long h[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * P;

    string str;
    while (cin >> str)
    {
        int n = str.size();
        for (int i = 1; i <= n; ++i)
            h[i] = h[i - 1] * P + str[i - 1];

        for (int i = 1; i <= n; ++i)
            if (h[i] == h[n] - h[n - i] * fact[i])
                printf("%d ", i);
        putchar('\n');
    }

    return 0;
}
