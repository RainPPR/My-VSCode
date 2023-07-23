#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 10;

int trie[N][26], idx = 0;
bool is[N];

void insert(const string &str)
{
    int root = 0;
    for (char i : str)
    {
        int st = i - 'a';
        if (!trie[root][st])
            trie[root][st] = ++idx;
        root = trie[root][st];
    }
    is[root] = true;
}

bool find(const string &str)
{
    int root = 0;
    for (char i : str)
    {
        int st = i - 'a';
        if (!trie[root][st])
            return false;
        root = trie[root][st];
    }
    return is[root];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string str;
        cin >> str;
        insert(str);
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        string str;
        cin >> str;
        cout << (find(str) ? "yes" : "no") << endl;
    }

    return 0;
}
