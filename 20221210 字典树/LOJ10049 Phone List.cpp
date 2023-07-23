#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

string str[N];

int trie[N][10], idx;

void insert(const string &str)
{
    int root = 0;
    for (char i : str)
    {
        int st = i - '0';
        if (!trie[root][st])
            trie[root][st] = ++idx;
        root = trie[root][st];
    }
}

bool find(const string &str)
{
    int root = 0;
    for (char i : str)
    {
        int st = i - '0';
        if (!trie[root][st])
            return false;
        root = trie[root][st];
    }
    for (int i = 0; i < 10; ++i)
        if (trie[root][i])
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        idx = 0;
        memset(trie, 0, sizeof trie);

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> str[i], insert(str[i]);

        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (find(str[i]))
            {
                flag = true;
                break;
            }
        }

        cout << (flag ? "NO" : "YES") << endl;
    }
    return 0;
}
