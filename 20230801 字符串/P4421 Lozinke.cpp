#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int P = 1e9 + 7;

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

ull pw[N];
ull h[N][M];

unordered_set<ull> sub;
unordered_map<ull, int> res;

int main()
{
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * P;

    int n = read();

    for (int i = 0; i < n; ++i)
    {
        pwd[i] = readline();

        sub.clear();

        h[i][0] = pwd[i][0];
        for (int k = 1; k < pwd[i].size(); ++k)
            h[i][k] = h[i][k - 1] * P + pwd[i][k];

        for (int r = 0; r < pwd[i].size(); ++r)
            sub.insert(h[i][r]);
        for (int l = 1; l < pwd[i].size(); ++l)
            for (int r = l; r < pwd[i].size(); ++r)
                sub.insert(h[i][r] - h[i][l - 1] * pw[r - l + 1]);

        for (ull k : sub)
            ++res[k];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += res[h[i][pwd[i].size() - 1]];

    printf("%d\n", ans - n);
    return 0;
}