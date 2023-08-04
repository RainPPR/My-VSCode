#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e4 + 5;

int T, n;

struct node
{
    int A, B, D;
    bool operator<(const node &t) const
    {
        if (D != t.D)
            return D < t.D;
        if (D <= 0)
            return A < t.A;
        return B > t.B;
    }
} nodes[N];

signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);

        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld %lld", &nodes[i].A, &nodes[i].B);
            if (nodes[i].A == nodes[i].B)
                nodes[i].D = 0;
            else if (nodes[i].A < nodes[i].B)
                nodes[i].D = -1;
            else
                nodes[i].D = 1;
        }

        sort(nodes + 1, nodes + 1 + n);

        int C = nodes[1].A + nodes[1].B, S = nodes[1].A;
        for (int i = 2; i <= n; ++i)
            S += nodes[i].A, C = max(C, S) + nodes[i].B;

        printf("%lld\n", C);
    }
    return 0;
}
