#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10;
const int M = 11;

int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

string readline()
{
    string s;
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    for (; ch > 13; ch = getchar())
        s.push_back(ch);
    return s;
}

string pwd[N];

unordered_set<string> sub;
unordered_map<string, int> res;

int main()
{
    int n = read();

    for (int i = 0; i < n; ++i)
    {
        pwd[i] = readline();

        sub.clear();
        for (int l = 0; l < pwd[i].size(); ++l)
            for (int r = l; r < pwd[i].size(); ++r)
                sub.insert(pwd[i].substr(l, r - l + 1));

        for (string k : sub)
            ++res[k];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += res[pwd[i]];

    printf("%d\n", ans - n);
    return 0;
}