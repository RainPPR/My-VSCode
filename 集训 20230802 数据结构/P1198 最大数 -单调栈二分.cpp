#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 8e5 + 10;

struct node
{
    int id, val;
} stk[N];

int top;

signed main()
{
    int q, mod;
    scanf("%lld %lld", &q, &mod);

    char op[2];
    int lt = 0, n;
    for (int i = 1; i <= q; ++i)
    {
        scanf("%s %lld", op, &n);
        if (op[0] == 'A')
        {
            n = (n + lt) % mod;

            while (top && stk[top].val < n)
                --top;
            stk[++top] = {i, n};
        }
        else
        {
            n = top - n + 1;

            int l = 1, r = top;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (stk[mid].id < n)
                    l = mid + 1;
                else
                    r = mid;
            }

            lt = stk[l].val;
            printf("%lld\n", lt);
        }
    }

    return 0;
}
