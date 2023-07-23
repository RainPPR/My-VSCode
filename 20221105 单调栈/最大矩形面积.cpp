#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int h[N];

struct Point
{
    int height, width;
    Point()
    {
        height = width = 0;
    }
    Point(int _h, int _w)
    {
        height = _h, width = _w;
    }
} s[N];

int main()
{
    while (1)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", h + i);

        if (!n)
            break;

        h[n++] = -1;

        int top = 0;
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            while (top && h[i] < s[top].height)
            {
                sum += s[top].width;
                ans = max(ans, (long long)sum * s[top].height);
                --top;
            }

            if (h[i] == s[top].height)
                ++s[top].width;
            else
                s[++top] = Point(h[i], 1);
        }

        printf("%lld\n", ans);
    }
}
