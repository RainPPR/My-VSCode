#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef multiset<int>::iterator msi;

template <typename _Tp>
_Tp read()
{
    _Tp num = 0, flag = 1;
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

int n, m;
int h[N], e[N], w[N], ne[N], idx;

void add(int a, int b, int l)
{
    e[idx] = b;
    w[idx] = l;
    ne[idx] = h[a];
    h[a] = idx++;
}

int mid, cnt;

int dfs(int u, int fa)
{
    multiset<int> s;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;

        int dis = dfs(v, u) + w[i];
        if (dis >= mid)
            ++cnt;
        else
            s.insert(dis);
    }

    int maxl = 0;
    while (s.size())
    {
        msi it = s.begin();
        if (s.size() == 1)
            return max(maxl, *it);

        msi t = s.lower_bound(mid - *it);
        if (t == it && s.count(*it) == 1)
            ++t;

        if (t == s.end())
            maxl = max(maxl, *it);
        else
            ++cnt, s.erase(t);
        s.erase(s.find(*it));
    }
    return maxl;
}

int main()
{
    // freopen("track.in", "r", stdin);
    // freopen("track.out", "w", stdout);

    memset(h, -1, sizeof h);
    n = read<int>(), m = read<int>();

    for (int i = 1; i < n; ++i)
    {
        int a = read<int>(), b = read<int>(), l = read<int>();
        add(a, b, l);
        add(b, a, l);
    }

    int ans = -1;
    int l = 0, r = 5e8;
    while (l < r)
    {
        cnt = 0, mid = l + r >> 1;
        dfs(1, 1);
        if (cnt >= m)
            l = mid + 1, ans = max(ans, mid);
        else
            r = mid;
    }
    printf("%d\n", ans);

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}