#include <bits/stdc++.h>

using namespace std;

const unsigned long long P = 3079;
const unsigned long long MOD = 1e9 + 9;

bool h[MOD];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--)
    {
        string type, name;
        cin >> type;
        getline(cin, name);

        unsigned long long hs = 0;
        for (char i : name)
            hs = hs * P + i;
        hs %= MOD;

        if (type == "add")
            h[hs] = true;
        else
            cout << (h[hs] ? "yes" : "no") << endl;
    }
    return 0;
}
