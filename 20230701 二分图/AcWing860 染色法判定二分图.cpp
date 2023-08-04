#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 200010;

int n, m;
int color[N];

int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (color[j] == c)
            return false;
        else if (!color[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
    }

    return true;
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d %d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}