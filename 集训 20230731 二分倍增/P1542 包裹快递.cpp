#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const long double ex = 1e-6;

int n;
struct node
{
    int l, r, s;
} nodes[N];

bool check(long double d)
{
    long double time = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        time += nodes[i].s / d;
        if (time > nodes[i].r)
            return false;
        else if (time < nodes[i].l)
            time = nodes[i].l;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d %d", &nodes[i].l, &nodes[i].r, &nodes[i].s);

    long double l = 1, r = 1e8;
    while (abs(r - l) > ex)
    {
        long double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    printf("%.2LF\n", l);
    return 0;
}