#include <bits/stdc++.h>

#define rr read()
#define rl readline()

using namespace std;

const int N = 6e5 + 10;

inline int read()
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

inline string readline()
{
    string str;
    char ch = getchar();
    while (ch <= 13)
        ch = getchar();
    for (; ch > 13; ch = getchar())
        str.push_back(ch);
    return str;
}

int son[N][3], idx;
int over[N];

void insert(string str)
{
    int root = 0;
    for (char i : str)
    {
        int c = i - 'a';
        if (!son[root][c])
            son[root][c] = ++idx;
        root = son[root][c];
    }
    over[root] = 1;
}

bool dfs(const string &str, int root = 0, int k = 0, int bk = 0)
{
    if (k == str.size())
        return bk && over[root];

    int c = str[k] - 'a';
    if (son[root][c] && dfs(str, son[root][c], k + 1, bk))
        return true;

    if (bk)
        return false;

    for (int i = 0; i < 3; ++i)
        if (i != c && son[root][i] && dfs(str, son[root][i], k + 1, bk + 1))
            return true;

    return false;
}

int main()
{
    int n = rr, m = rr;
    for (int i = 1; i <= n; ++i)
        insert(rl);
    for (int i = 1; i <= m; ++i)
        printf(dfs(rl) ? "YES\n" : "NO\n");
    return 0;
}
