#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<string> dict;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        dict.emplace(str);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        cout << (dict.count(str) ? "yes" : "no") << endl;
    }

    return 0;
}
