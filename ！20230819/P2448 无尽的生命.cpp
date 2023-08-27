#include <bits/stdc++.h>

#define int long long

#define rr read()

using namespace std;

const int N = 4e5 + 10;

inline int lobit(int x)
{
    return x & -x;
}

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

struct node
{
    int x, y;
    node()
    {
        x = y = 0;
    }
    node(int _x, int _y)
    {
        x = _x, y = _y;
    }
    bool operator<(const node &t) const
    {
        return x < t.x;
    }
};

vector<node> q;
vector<node> a;

set<node> uq;
set<node> ad;

unordered_map<int, int> to;

int s[N];

void upd(int x, int t)
{
    for (; x < N; x += lobit(x))
        s[x] += t;
}

int que(int x)
{
    int res = 0;
    for (; x; x -= lobit(x))
        res += s[x];
    return res;
}

signed main()
{
    int m = rr;
    for (int i = 0; i < m; ++i)
        q.push_back({rr, rr}), uq.emplace(q[i].x, 1), uq.emplace(q[i].y, 1);

    set<node>::iterator _a = uq.begin(), _b(_a);
    for (++_b; _b != uq.end(); ++_a, ++_b)
        if (_a->x < _b->x - 1)
            ad.emplace(_b->x - 1, _b->x - _a->x - 1);
    uq.insert(ad.begin(), ad.end());

    int n = 0;
    for (node i : uq)
        to[i.x] = n++, a.push_back({n, i.y});

    for (int i = 0; i < m; ++i)
        swap(a[to[q[i].x]], a[to[q[i].y]]);

    int ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        ans += que(a[i].x - 1) * a[i].y;
        upd(a[i].x, a[i].y);
    }

    printf("%lld\n", ans);
    return 0;
}