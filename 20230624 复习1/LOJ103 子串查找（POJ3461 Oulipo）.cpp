#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int P = 1e9 + 7;

unsigned long long fact[N];
unsigned long long h[N];

inline int calc(const string &str, const string &p)
{
    const int n = str.size(), m = p.size();

    h[0] = 0;
    for (int i = 1; i <= n; ++i)
        h[i] = h[i - 1] * P + str[i - 1];

    unsigned long long s = 0;
    for (char i : p)
        s = s * P + i;

    int ans = 0;
    for (int i = m; i <= n; ++i)
        if (s == h[i] - h[i - m] * fact[m])
            ++ans;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * P;

    string str, p;
    cin >> str >> p;
    cout << calc(str, p) << endl;

    return 0;
}
