#include <bits/stdc++.h>

#define rr read()
#define rw readword()

using namespace std;

const int N = 2e5 + 10;

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

inline bool iswordsep(const char &ch)
{
    return ch == ' ' || ch <= 13;
}

inline string readword()
{
    string str;
    char ch = getchar();
    while (iswordsep(ch))
        ch = getchar();
    while (!iswordsep(ch))
        str += ch, ch = getchar();
    return str;
}

int n, q;

struct _q
{
    string op;
    int x, y;
} a[N];

int from[N];
unordered_map<int, int> to;

set<int> s[N];
int c[N * 4];

void modify(const int &k, const int &l, const int &r, const int &x, const int &y)
{
    if (l > x || r < x)
        return;
    if (l == r)
    {
        c[k] = y;
        return;
    }

    int mid = l + r >> 1;
    modify(k * 2, l, mid, x, y);
    modify(k * 2 + 1, mid + 1, r, x, y);

    c[k] = max(c[k * 2], c[k * 2 + 1]);
}

int query(const int &k, const int &l, const int &r, const int &a, const int &b)
{
    if (a >= r || c[k] <= b)
        return -1;
    if (l == r)
        return l;

    int mid = l + r >> 1, res = query(k * 2, l, mid, a, b);
    return res == -1 ? query(k * 2 + 1, mid + 1, r, a, b) : res;
}

int main()
{
    memset(c, -1, sizeof c);

    q = rr;
    for (int i = 1; i <= q; ++i)
        a[i] = {rw, rr, rr}, from[i] = a[i].x;

    sort(from + 1, from + 1 + q);
    n = unique(from + 1, from + 1 + q) - from - 1;

    for (int i = 1; i <= n; ++i)
        to[from[i]] = i;
    for (int i = 1; i <= q; ++i)
    {
        int &x = a[i].x = to[a[i].x], &y = a[i].y;
        if (a[i].op == "add")
            s[x].insert(y), modify(1, 1, n, x, *s[x].rbegin());
        else if (a[i].op == "remove")
            s[x].erase(y), modify(1, 1, n, x, s[x].size() ? *s[x].rbegin() : -1);
        else
        {
            int p = query(1, 1, n, x, y);
            p == -1 ? printf("-1\n") : printf("%d %d\n", from[p], *s[p].upper_bound(y));
        }
    }

    return 0;
}
