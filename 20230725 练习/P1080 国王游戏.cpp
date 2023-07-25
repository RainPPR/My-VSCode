#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a, b;

struct node
{
    int l, r;
    int s;

    bool operator<(const node &a) const
    {
        return this->s < a.s;
    }
} nodes[N];

struct bigint
{
    vector<int> a;

    void init(int x)
    {
        a.clear();
        while (x)
        {
            a.push_back(x % 10);
            x /= 10;
        }
    }
    void init(bigint *t)
    {
        this->a = t->a;
    }

    void print()
    {
        for (int i = a.size() - 1; i >= 0; --i)
            putchar(a[i] + '0');
        putchar('\n');
    }

    void times(int x)
    {
        int jw = 0;
        for (int &i : a)
        {
            i = i * x + jw;
            jw = i / 10;
            i %= 10;
        }
        while (jw)
        {
            a.push_back(jw % 10);
            jw /= 10;
        }
    }
    void sub(int x)
    {
        int now = 0;

        vector<int> res;
        for (int i = a.size() - 1; i >= 0; --i)
        {
            now = now * 10 + a[i];
            if (now >= x)
            {
                res.push_back(now / x);
                now %= x;
            }
            else if (res.size())
                res.push_back(0);
        }

        a.clear();
        for (int i = res.size() - 1; i >= 0; --i)
            a.push_back(res[i]);
    }

    bool gr(bigint *t)
    {
        if (this->a.size() > t->a.size())
            return true;
        if (this->a.size() < t->a.size())
            return false;
        for (int i = a.size() - 1; i >= 0; --i)
        {
            if (this->a[i] > t->a[i])
                return true;
            else if (this->a[i] < t->a[i])
                return false;
        }
        return false;
    }
};

bigint *calc()
{
    bigint *ans = new bigint, *times = new bigint;
    times->init(a);

    bigint *now = new bigint;
    for (int i = 1; i <= n; ++i)
    {
        now->init(times);
        now->sub(nodes[i].r);
        times->times(nodes[i].l);
        if (now->gr(ans))
            ans->init(now);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);

    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &nodes[i].l, &nodes[i].r);
        nodes[i].s = nodes[i].l * nodes[i].r;
    }

    sort(nodes + 1, nodes + n + 1);

    bigint *ans = calc();
    ans->print();
    return 0;
}