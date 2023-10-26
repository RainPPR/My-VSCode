#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
const double eps = 1e-8;

int n;
double x[N], y[N], k[N], b[N];

bool check(double mid)
{
    double l = 0, r = 1e5;
    for (int i = 2; i <= n; ++i)
    {
        if (k[i] < 0)
            l = max(l, (mid - b[i]) / k[i]);
        else if (k[i] > 0)
            r = min(r, (mid - b[i]) / k[i]);
        else if (mid < b[i])
            return false;
    }
    return l <= r;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lf %lf", x + i, y + i);
        k[i] = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
        b[i] = y[i] - k[i] * x[i];
    }

    double l = 0, r = 1e6;
    while (l + eps < r)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    printf("%.2lf\n", l);
    return 0;
}