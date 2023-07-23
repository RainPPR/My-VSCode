#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 7;

bool h[N];

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    long long n = 1, res = 0;
    while (!h[n] && res <= 2e6)
        h[n] = true, n = (a * n + n % b) % c, ++res;

    if (res > 2e6)
        printf("-1\n");
    else
        printf("%lld\n", res);
    return 0;
}
