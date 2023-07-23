#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    
    while (n--)
    {
        long long t;
        scanf("%lld", &t);

        long long l = 0, r = 1e15;
        while (l < r)
        {
            long long mid = l + r >> 1;
            if (mid / x + mid / y < t)
                l = mid + 1;
            else
                r = mid;
        }

        if (l % x == 0 && l % y == 0)
            printf("Both\n");
        else if (l % x == 0)
            printf("Vova\n");
        else
            printf("Vanya\n");
    }
    return 0;
}
