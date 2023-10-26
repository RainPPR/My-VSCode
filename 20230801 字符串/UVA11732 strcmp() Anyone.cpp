#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 10;
const int S = 1e3 + 10;
const int M = N * S;

int pos[256];

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
    string str;
    for (char ch = getchar(); ch > 13; ch = getchar())
        str += ch;
    return str;
}

int son[M][63], idx;
int cnt[M], ed[M];

long long ans;

void insert(string str)
{
    int root = 0, i;
    for (i = 0; i < str.size(); ++i)
    {
        int c = pos[str[i]];

        if (!son[root][c])
            son[root][c] = ++idx;

        ans += 1ll * (cnt[root] - cnt[son[root][c]]) * (i + i + 1);

        ++cnt[root];
        root = son[root][c];
    }

    ans += 1ll * ed[root] * (i + i + 2);
    ans += 1ll * (cnt[root] - ed[root]) * (i + i + 1);

    ++ed[root];
    ++cnt[root];
}

int main()
{
    int t = 0;
    for (int i = 0; i < 26; ++i)
        pos[i + 'a'] = t++;
    for (int i = 0; i < 26; ++i)
        pos[i + 'A'] = t++;
    for (int i = 0; i < 10; ++i)
        pos[i + '0'] = t++;

    int n, now = 0;
    while (n = read())
    {
        for (int i = 0; i <= idx; i++)
        {
            cnt[i] = ed[i] = 0;
            for (int j = 0; j < 63; j++)
                son[i][j] = 0;
        }

        idx = ans = 0;
        for (int i = 0; i < n; ++i)
            insert(readline());

        printf("Case %d: %lld\n", ++now, ans);
    }

    return 0;
}