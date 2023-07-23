#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;

int trie[N][2];
int idx;

void insert(int x)
{
    int root = 0;
    for (int i = 31; i >= 0; --i)
    {
        int st = x >> i & 1;
        if (!trie[root][st])
            trie[root][st] = ++idx;
        root = trie[root][st];
    }
}

int search(int x)
{
    int root = 0, res = 0;
    for (int i = 31; i >= 0; --i)
    {
        int st = x >> i & 1;
        if (trie[root][!st])
            st ^= 1;
        root = trie[root][st];
        res = (res << 1) | st;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    int ans = -1;
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", &t);
        insert(t);
        ans = max(ans, t ^ search(t));
    }

    printf("%d\n", ans);
    return 0;
}
