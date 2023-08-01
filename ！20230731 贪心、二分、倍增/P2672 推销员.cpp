#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node
{
    int s, a;
    bool operator<(const node &t) const
    {
        return a > t.a;
    }
} nodes[N];

int sum[N];
int mxs[N];
int mxa[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &nodes[i].s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &nodes[i].a);

    sort(nodes + 1, nodes + 1 + n);

    for (int i = n; i >= 1; --i)
        mxa[i] = max(mxa[i + 1], nodes[i].s * 2 + nodes[i].a);
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + nodes[i].a;
        mxs[i] = max(mxs[i - 1], nodes[i].s);
    }

    for (int i = 1; i <= n; ++i)
        printf("%d\n", max(sum[i] + mxs[i] * 2, sum[i - 1] + mxa[i]));
    return 0;
}