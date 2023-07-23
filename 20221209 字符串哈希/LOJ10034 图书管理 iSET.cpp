#include <bits/stdc++.h>

using namespace std;

const unsigned long long P = 3079;

unordered_set<unsigned long long> h;

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

        if (type == "add")
            h.insert(hs);
        else
            cout << (h.count(hs) ? "yes" : "no") << endl;
    }
    return 0;
}
