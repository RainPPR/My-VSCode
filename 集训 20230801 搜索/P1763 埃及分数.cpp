#include <bits/stdc++.h>

#define gcd __gcd

using namespace std;

vector<int> ans;
vector<int> res;

int lgst = 2e9;

pair<int, int> sub(pair<int, int> a, pair<int, int> b)
{
    int g = gcd(a.second, b.second);
    int l = b.second / g * a.first - a.second / g * b.first;
    int r = a.second / g * b.second;
    return make_pair(l, r);
}

bool iddfs(int now, pair<int, int> re, int last, int limit)
{
    if (now == limit)
    {
        if (re.first != 0)
            return false;
        if (last < lgst)
            ans = res, lgst = last;
        return true;
    }

    int l = max((re.second + re.first - 1) / re.first, last + 1), r = (limit - now) * re.second / re.first;

    bool flag = false;
    for (int i = l; i <= r; ++i)
    {
        res.push_back(i);
        if (iddfs(now + 1, sub(re, make_pair(1, i)), i, limit))
            flag = true;
        res.pop_back();
    }
    return flag;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int limit = 0;
    while (!iddfs(0, make_pair(a, b), 0, limit))
        ++limit;

    for (int i : ans)
        printf("%d ", i);
    return 0;
}