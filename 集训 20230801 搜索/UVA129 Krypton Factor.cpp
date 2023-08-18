#include <bits/stdc++.h>

using namespace std;

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

void write(string str)
{
    for (int i = 0; i < str.size();)
    {
        putchar(str[i++]);
        if (i % 64 == 0)
            putchar('\n');
        else if (i % 4 == 0 && i != str.size())
            putchar(' ');
    }
    if (str.size() % 64)
        putchar('\n');
}

int n, l;
vector<string> ans;

bool check(string res)
{
    for (int len = res.size() >> 1; len >= 1; --len)
        if (res.substr(res.size() - len, len) == res.substr(res.size() - 2 * len, len))
            return false;
    return true;
}

void dfs(string now = "")
{
    for (int i = 0; i < l; ++i)
    {
        string t = now + char('A' + i);
        if (ans.size() >= n)
            return;
        if (check(t))
            ans.push_back(t), dfs(t);
    }
}

void solve()
{
    ans.clear();
    dfs("");
    write(ans[n - 1]);
    printf("%d\n", ans[n - 1].size());
}

int main()
{
    n = read(), l = read();
    while (n && l)
        solve(), n = read(), l = read();
    return 0;
}