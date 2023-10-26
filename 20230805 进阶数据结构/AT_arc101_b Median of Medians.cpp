#include <bits/stdc++.h>

#define int long long

#define rr read()

using namespace std;

const int N = 2e5 + 10;

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

int n, tar;
int a[N], k[N];

int b[N], s[N];

inline int lobit(int x)
{
    return x & -x;
}

inline void add(int x)
{
    for (; x <= 2 * n + 1; x += lobit(x))
        ++s[x];
}

inline int sum(int x)
{
    int res = 0;
    for (; x; x -= lobit(x))
        res += s[x];
    return res;
}

bool check(int mid)
{
    for (int i = 1; i <= n; ++i)
        b[i] = b[i - 1] + (a[i] > mid ? -1 : 1);

    for (int i = 1; i <= n; ++i)
        s[i] = s[i + n] = 0;

    add(n + 1);

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += sum(b[i] + n), add(b[i] + n + 1);
    return res >= tar;
}

signed main()
{
    n = rr, tar = 1ll * n * (n + 1) / 4 + 1;
    for (int i = 1; i <= n; ++i)
        k[i] = a[i] = rr;

    sort(k + 1, k + 1 + n);

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(k[mid]))
            r = mid;
        else
            l = mid + 1;
    }

    printf("%lld\n", k[l]);
    return 0;
}
