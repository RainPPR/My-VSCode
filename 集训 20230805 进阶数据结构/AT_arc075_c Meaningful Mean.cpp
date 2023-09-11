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

inline int lowbit(int x) { return x & -x; }

int a[N], b[N];

int n, k, res;

void msort(int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;
    msort(l, mid), msort(mid + 1, r);

    int i = l, j = mid + 1, c = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            b[c++] = a[j++], res += mid - i + 1;
        else
            b[c++] = a[i++];
    }

    while (i <= mid)
        b[c++] = a[i++];
    while (j <= r)
        b[c++] = a[j++];

    for (int t = l; t <= r; ++t)
        a[t] = b[t];
}

signed main()
{
    n = rr, k = rr;
    for (int i = 1; i <= n; ++i)
        a[i] = a[i - 1] + rr - k;

    msort(0, n);

    printf("%lld\n", res);
    return 0;
}
