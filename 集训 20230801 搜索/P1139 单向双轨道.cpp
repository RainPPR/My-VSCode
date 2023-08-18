#include <bits/stdc++.h>

const int N = 30;

using namespace std;

const int op_from[6] = {0, 0, 0, 1, 1, 2};
const int op_to[6] = {1, 2, 3, 2, 3, 3};

int n;

struct _now
{
    string s[3];
    string target;
} now;

struct
{
    char id;
    char from, to;
} ans[N * 3];

int f()
{
    return now.target.size();
}

bool operate(int op)
{
    string &a = now.s[0];
    string &b = now.s[1];
    string &c = now.s[2];
    string &t = now.target;

    if (op == 0) // a -> b
    {
        if (!a.size())
            return false;
        b.push_back(a.back());
        a.pop_back();
        return true;
    }
    else if (op == 1) // a -> c
    {
        if (!a.size())
            return false;
        c.push_back(a.back());
        a.pop_back();
        return true;
    }
    else if (op == 2) // a -> d
    {
        if (!a.size())
            return false;
        if (a.back() != t.back())
            return false;
        a.pop_back();
        t.pop_back();
        return true;
    }
    else if (op == 3) // b -> c
    {
        if (!b.size())
            return false;
        c.push_back(b.back());
        b.pop_back();
        return true;
    }
    else if (op == 4) // b -> d
    {
        if (!b.size())
            return false;
        if (b.back() != t.back())
            return false;
        b.pop_back();
        t.pop_back();
        return true;
    }
    else if (op == 5) // c -> d
    {
        if (!c.size())
            return false;
        if (c.back() != t.back())
            return false;
        c.pop_back();
        t.pop_back();
        return true;
    }

    return false;
}

bool ida_star(int k, int limit, int last)
{
    int ft = f();
    if (k + ft > limit)
        return false;
    if (!ft)
        return true;

    for (int i = 0; i <= 5; ++i)
    {
        if (op_from[i] == last)
            continue;
        _now backup = now;
        if (operate(i))
        {
            ans[k] = {backup.s[op_from[i]].back(), char(op_from[i] + 'A'), char(op_to[i] + 'A')};
            if (ida_star(k + 1, limit, op_to[i]))
                return true;
        }
        now = backup;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> now.target;

    for (int i = 0; i < n; ++i)
        now.s[0].push_back(i + 'a');

    int max_limit = n * 3, limit = 0;
    while (limit <= max_limit && !ida_star(0, limit, -1))
        ++limit;

    if (limit > max_limit)
        cout << "NO" << endl;
    else
    {
        for (int i = 0; i < limit; ++i)
            cout << ans[i].id << " " << ans[i].from << " " << ans[i].to << endl;
    }
    return 0;
}