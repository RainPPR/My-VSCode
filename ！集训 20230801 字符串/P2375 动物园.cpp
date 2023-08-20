#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const long long mod = 1e9 + 7;

int f[N];
int g[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        f[0] = -1;
        for (int j = 0, k = -1; j < str.size();)
        {
            if (k == -1 || str[j] == str[k])
                f[++j] = ++k, g[j] = g[k] + 1;
            else
                k = f[k];
        }

        long long res = 1;
        for (int j = 0, k = -1; j < str.size();)
        {
            if (k == -1 || str[j] == str[k])
            {
                ++k, ++j;
                while ((k << 1) > j)
                    k = f[k];
                res = res * (g[k] + 1) % mod;
            }
            else
                k = f[k];
        }

        cout << res << endl;
    }

    return 0;
}