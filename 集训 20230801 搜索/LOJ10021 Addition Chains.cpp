#include <bits/stdc++.h>

using namespace std;

const int N = 110;

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

int n;
int path[N];

bool iddfs(int k, int limit)
{
    if (k > limit)
        return false;
    if (path[k - 1] == n)
        return true;

    bool st[N] = {0};
    for (int i = k - 1; i >= 0; --i)
    {
        for (int j = i; j >= 0; --j)
        {
            int s = path[i] + path[j];
            if (s > n || s <= path[k - 1] || st[s])
                continue;
            st[s] = true;
            path[k] = s;
            if (iddfs(k + 1, limit))
                return true;
        }
    }
    return false;
}

int main()
{
    path[0] = 1;
    while (n = read())
    {
        int depth = 1;
        while (!iddfs(1, depth))
            ++depth;
        for (int i = 0; i < depth; ++i)
            printf("%d ", path[i]);
        putchar('\n');
    }
    return 0;
}
