#include <bits/stdc++.h>

using namespace std;

unordered_set<string> dict;

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

        if (type == "add")
            dict.emplace(name);
        else
            cout << (dict.count(name) ? "yes" : "no") << endl;
    }
    return 0;
}