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

    for (int i = 1; cin >> str[0]; ++i)
    {
        idx = 0;
        memset(trie, 0, sizeof trie);

        int n = 1;
        while (1)
        {
            cin >> str[n];
            if (str[n] == "9")
                break;
            insert(str[n]);
            ++n;
        }

        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (find(str[i]))
            {
                flag = true;
                break;
            }
        }

        cout << "Set " << i << " is" << (flag ? " not " : " ") << "immediately decodable" << endl;
    }
    return 0;
}
