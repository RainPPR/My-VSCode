#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;

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
    int a, b;
    bool operator<(const node &t) const
    {
        return a - b > t.a - t.b;
    }
} nodes[N];

int lmx[N], rmx[N];
priority_queue<int, vector<int>, greater<int>> lq, rq;

signed main()
{
    // input

    int x = read(), y = read(), z = read();
    int n = x + y + z;

    int sumc = 0;

    for (int i = 1; i <= n; ++i)
    {
        nodes[i].a = read();
        nodes[i].b = read();

        int c = read();
        nodes[i].a -= c;
        nodes[i].b -= c;
        sumc += c;
    }

    sort(nodes + 1, nodes + 1 + n);

    // calculate lmx

    for (int i = 1; i <= x; ++i)
    {
        lq.push(nodes[i].a);
        lmx[i] = lmx[i - 1] + nodes[i].a;
    }

    for (int i = x + 1; i <= n; ++i)
    {
        lq.push(nodes[i].a);
        lmx[i] = lmx[i - 1] + nodes[i].a - lq.top();
        lq.pop();
    }

    // calculate rmx

    for (int i = n; i >= n - y + 1; --i)
    {
        rq.push(nodes[i].b);
        rmx[i] = rmx[i + 1] + nodes[i].b;
    }

    for (int i = n - y; i; --i)
    {
        rq.push(nodes[i].b);
        rmx[i] = rmx[i + 1] + nodes[i].b - rq.top();
        rq.pop();
    }

    // calculate answer

    int ans = -2e18;
    for (int i = x; i <= n - y; ++i)
        ans = max(ans, sumc + lmx[i] + rmx[i + 1]);

    // output

    printf("%lld\n", ans);
    return 0;
}