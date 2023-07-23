#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, m;

struct mess
{
    int n;
    bool x[N];
};

int trie[N][2], idx;
int cnt[N], child[N];

void insert(const mess &t)
{
    int root = 0;
    for (int i = 0; i < t.n; ++i)
    {
        ++child[root];
        if (!trie[root][t.x[i]])
            trie[root][t.x[i]] = ++idx;
        root = trie[root][t.x[i]];
    }
    ++cnt[root];
}

int find(const mess &t)
{
    int ans = 0;

    int root = 0;
    for (int i = 0; i < t.n; ++i)
    {
        if (!trie[root][t.x[i]])
        {
            root = -1;
            break;
        }
        root = trie[root][t.x[i]];
        ans += cnt[root];
    }

    if (root != -1)
        ans += child[root];

    return ans;
}

int main()
{
    mess t;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t.n);
        for (int j = 0; j < t.n; ++j)
            scanf("%d", t.x + j);
        insert(t);
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &t.n);
        for (int j = 0; j < t.n; ++j)
            scanf("%d", t.x + j);
        printf("%d\n", find(t));
    }

    return 0;
}