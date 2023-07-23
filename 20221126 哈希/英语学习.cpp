#include <bits/stdc++.h>

using namespace std;

const int P = 53;
const int MOD = 1e9 + 7;

bool h[MOD + 10];

int myhash(string str)
{
    unsigned long long k = 0;
    for (char i : str)
        k = (k + i - 'a') * P % MOD;
    return k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;
    while (n--)
        cin >> str, h[myhash(str)] = true;

    int ans = 0;
    while (cin >> str)
        if (!h[myhash(str)])
            ++ans;

    cout << ans << endl;
    return 0;
}
