#include <bits/stdc++.h>

using namespace std;

const int N = 24;

int op[8][7] =
    {{0, 2, 6, 11, 15, 20, 22},
     {1, 3, 8, 12, 17, 21, 23},
     {10, 9, 8, 7, 6, 5, 4},
     {19, 18, 17, 16, 15, 14, 13},
     {23, 21, 17, 12, 8, 3, 1},
     {22, 20, 15, 11, 6, 2, 0},
     {13, 14, 15, 16, 17, 18, 19},
     {4, 5, 6, 7, 8, 9, 10}};

int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};

int q[N];
int path[100];

int read()
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

int f()
{
    int sum[4] = {0};

    for (int i = 0; i < 8; ++i)
        ++sum[q[center[i]]];
    int s = max({sum[1], sum[2], sum[3]});

    return 8 - s;
}

void operate(int x)
{
    int t = q[op[x][0]];
    for (int i = 0; i < 6; ++i)
        q[op[x][i]] = q[op[x][i + 1]];
    q[op[x][6]] = t;
}

bool ida_star(int now, int limit, int last)
{
    if (now + f() > limit)
        return false;
    if (!f())
        return true;

    for (int i = 0; i < 8; ++i)
    {
        if (opposite[i] == last)
            continue;
        operate(i);
        path[now] = i;

        if (ida_star(now + 1, limit, i))
            return true;
        operate(opposite[i]);
    }
    return false;
}

int main()
{
    while (q[0] = read())
    {
        for (int i = 1; i < N; ++i)
            q[i] = read();

        int limit = 0;
        while (!ida_star(0, limit, -1))
            ++limit;

        if (!limit)
            printf("No moves needed\n");
        else
        {
            for (int i = 0; i < limit; ++i)
                putchar(path[i] + 'A');
            putchar('\n');
        }
        printf("%d\n", q[6]);
    }

    return 0;
}
