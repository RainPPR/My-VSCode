#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef unsigned long long ull;

const int N = (1 << 20) + 10;
const int p = 1e9 + 7;

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

int lobit(int x)
{
    return x & -x;
}

ull pw[N];
ull h[N];

int c[256] = {0};

int fc[N];

int n;
int ft[N];

void add(int x)
{
    for (++x; x <= n; x += lobit(x))
        ++ft[x];
}

int sum(int x)
{
    int sum = 0;
    for (++x; x; x -= lobit(x))
        sum += ft[x];
    return sum;
}

signed main()
{
    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);

    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * p;

    int T = read();
    while (T--)
    {
        memset(ft, 0, sizeof ft);

        // input and hash
        vector<char> s;
        for (char ch = getchar(); isalpha(ch); ch = getchar())
            s.push_back(ch);

        n = s.size();

        h[0] = s[0];
        for (int i = 1; i < n; ++i)
            h[i] = h[i - 1] * p + s[i];

        // calculate fc array
        memset(c, 0, sizeof c);

        fc[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (++c[s[i]] & 1)
                fc[i] = fc[i + 1] + 1;
            else
                fc[i] = fc[i + 1] - 1;
        }

        // calculate answer
        memset(c, 0, sizeof c);

        ++c[s[0]];
        int f = 1;
        add(1);

        int ans = 0;

        for (int i = 2; i < n; ++i)
        {
            ull k = h[i - 1];

            int res = sum(fc[i]);
            for (int l = i; l + i < n; l += i)
            {
                int r = l + i - 1;
                if (h[r] - h[l - 1] * pw[r - l + 1] != k)
                    break;
                res += sum(fc[r + 1]);
            }

            ans += res;

            if (++c[s[i - 1]] & 1)
                ++f;
            else
                --f;

            add(f);
        }

        printf("%lld\n", ans);
    }

    return 0;
}