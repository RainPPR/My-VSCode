#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int N = 5e5 + 10;
const int p = 1e9 + 7;

int n;
char str[N];

ull pw[N];

ull h[N];
ull rh[N];

ull get(int l, int r)
{
    if (l == 0)
        return h[r];
    return h[r] - h[l - 1] * pw[r - l + 1];
}

ull rget(int l, int r)
{
    if (r == n - 1)
        return rh[l];
    return rh[l] - rh[r + 1] * pw[r - l + 1];
}

struct
{
    int oui;
    char str[N];

    void insert(char c)
    {
        str[oui++] = c;
    }

    void output()
    {
        for (int i = 0; i < oui;)
        {
            for (int j = 0; i < oui && j < 80; ++i, ++j)
                putchar(str[i]);
            putchar('\n');
        }
    }
} res;

int main()
{
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * p;

    // input and hash
    scanf("%d", &n);

    char s[2];
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        str[i] = s[0];
    }

    h[0] = str[0];
    for (int i = 1; i < n; ++i)
        h[i] = h[i - 1] * p + str[i];
    rh[n - 1] = str[n - 1];
    for (int i = n - 2; i >= 0; --i)
        rh[i] = rh[i + 1] * p + str[i];

    // calculate answer
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (str[i] < str[j])
            res.insert(str[i++]);
        else if (str[j] < str[i])
            res.insert(str[j--]);
        else
        {
            int l = 1, r = j - i + 1 >> 1, k = 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (get(i, i + mid - 1) == rget(j - mid + 1, j))
                    l = mid, k = max(k, mid);
                else
                    r = mid - 1;
            }

            if (str[i + k] < str[j - k])
                res.insert(str[i++]);
            else
                res.insert(str[j--]);
        }
    }
    res.insert(str[i]);

    // output
    res.output();
    return 0;
}