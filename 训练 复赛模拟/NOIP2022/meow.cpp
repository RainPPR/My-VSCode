#include <bits/stdc++.h>

#define rr read()

#define m_debug 0

using namespace std;

const int N = 1e6 + 10;
const int K = 310;

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

int n, m, k;

struct dq
{
    deque<int> d;

    void clear() { d.clear(); }
    void push_top(int x) { d.push_front(x); }
    void push_back(int x) { d.push_back(x); }
    void pop_top() { d.pop_front(); }
    void pop_back() { d.pop_back(); }
    int top() { return d.front(); }
    int back() { return d.back(); }
    int size() { return d.size(); }

    bool top2()
    {
        int t = d.front();
        d.pop_front();
        int r = d.front();
        d.push_front(t);
        return t == r;
    }
};

struct state
{
    dq hp, a[K];

    int size()
    {
        int res = hp.size();
        for (int i = 1; i <= n; ++i)
            res += a[i].size();

        return res;
    }

    void clear()
    {
        hp.clear();
        for (int i = 1; i <= n; ++i)
            a[i].clear();
    }

    int h()
    {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res += a[i].size();
        return hp.size() + (res >> 1);
    }

} src;

struct solution
{
    int op;

    struct
    {
        int tp;
        int a, b;
    } s[2 * N];

    solution() { op = 0; }
    void push(int a, int b = -1) { s[++op] = {b == -1 ? 1 : 2, a, b}; }
    void pop() { --op; }
    void clear() { op = 0; }
    int size() { return op; }

    void print()
    {
        printf("%d\n", op);
        for (int i = 1; i <= op; ++i)
        {
            if (s[i].tp == 1)
                printf("1 %d\n", s[i].a);
            else
                printf("2 %d %d\n", s[i].a, s[i].b);
        }
    }
} res;

solution merge(solution t, int a, int b = -1)
{
    t.push(a, b);
    return t;
}

bool ida_star(state &k, const int &limit)
{
    if (k.h() + res.size() > limit)
        return false;
    if (k.size() == 0)
        return true;

    if (k.hp.size())
    {
        for (int i = 1; i <= n; ++i)
        {
            int go = k.hp.top(), inif = 0, aa, bb;

            k.a[i].push_top(k.hp.top());
            k.hp.pop_top();
            if (k.a[i].top2())
                inif = 1, aa = k.a[i].top(), k.a[i].pop_top(), bb = k.a[i].top(), k.a[i].pop_top();

            res.push(i);
            if (ida_star(k, limit))
                return true;
            res.pop();

            if (inif)
                k.a[i].push_top(bb), k.a[i].push_top(aa);
            k.hp.push_top(go);
            k.a[i].pop_top();
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j || k.a[i].size() == 0 || k.a[j].size() == 0)
                continue;

            int inif = 0, aa, bb;
            if (k.a[i].back() == k.a[j].back())
                inif = 1, aa = k.a[i].back(), bb = k.a[j].back(), k.a[i].pop_back(), k.a[j].pop_back();

            res.push(i, j);
            if (ida_star(k, limit))
                return true;
            res.pop();

            if (inif)
                k.a[j].push_back(bb), k.a[i].push_back(aa);
        }
    }

    return false;
}

void solve()
{
    n = rr, m = rr, k = rr;

    src.clear();
    for (int i = 0; i < m; ++i)
        src.hp.push_top(rr);

    int limit = m;

    if (m < 900)
        while (!ida_star(src, limit))
            ++limit, res.clear();

    res.print();
}

int main()
{
#ifndef mdebug
    freopen("meow.in", "r", stdin);
    freopen("meow.out", "w", stdout);
#endif

    int T = rr;
    while (T--)
        solve();

#ifndef mdebug
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
