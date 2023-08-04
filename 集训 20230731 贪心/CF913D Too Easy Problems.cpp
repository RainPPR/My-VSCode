#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, w;
int a[N], t[N];

bool check(int mid)
{
    vector<int> qt;
    for (int i = 1; i <= n; ++i)
        if (a[i] >= mid)
            qt.push_back(t[i]);
    if (mid > qt.size())
        return false;

    sort(qt.begin(), qt.end());

    int sum = 0;
    for (int i = 0; i < mid; i++)
        sum += qt[i];
    return sum <= w;
}

bool cmp(int k1, int k2)
{
    return t[k1] < t[k2];
}

int main()
{
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", a + i, t + i);

    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    printf("%d\n%d\n", l, l);

    vector<int> qt;
    for (int i = 1; i <= n; ++i)
        if (a[i] >= l)
            qt.push_back(i);

    sort(qt.begin(), qt.end(), cmp);

    for (int i = 0; i < l; i++)
        printf("%d ", qt[i]);
    return 0;
}