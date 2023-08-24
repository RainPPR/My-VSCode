#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 10;
const int K = 30;

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

int a[N];

int suml[N], sumr[N];
int ansl[N], ansr[N];

struct trie
{
    int son[N][2], idx;

    void insert(int x)
    {
        int root = 0;
        for (int k = K; k >= 0; --k)
        {
            int c = (x >> k) & 1;
            if (!son[root][c])
                son[root][c] = ++idx;
            root = son[root][c];
        }
    }

    int calc(int x)
    {
        int root = 0, res = 0;
        for (int k = K; k >= 0; --k)
        {
            int c = (x >> k) & 1;
            if (son[root][c ^ 1])
                c = c ^ 1, res += 1 << k;
            root = son[root][c];
        }
        return res;
    }
} tl, tr;

int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();

    for (int i = 1; i <= n; ++i)
        suml[i] = suml[i - 1] ^ a[i];
    for (int i = n; i >= 1; --i)
        sumr[i] = sumr[i + 1] ^ a[i];

    ansl[1] = suml[1], tl.insert(suml[1]);
    for (int i = 2; i <= n; ++i)
        ansl[i] = max({ansl[i - 1], tl.calc(suml[i]), suml[i]}), tl.insert(suml[i]);

    ansr[n] = sumr[n], tr.insert(sumr[n]);
    for (int i = n - 1; i >= 1; --i)
        ansr[i] = max({ansr[i + 1], tr.calc(sumr[i]), sumr[i]}), tr.insert(sumr[i]);

    int ans = 0;
    for (int i = 1; i < n; ++i)
        ans = max(ans, ansl[i] + ansr[i + 1]);

    printf("%d\n", ans);
    return 0;
}
