#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, k;
int a[N];
vector<int> g[N];

int in[N];
int mk[N];

vector<int> pt;
vector<int> sg[N];

bool istok(int mx)
{
    memset(in, 0, sizeof in);

    pt.clear();
    for (int i = 1; i <= n; ++i)
    {
        sg[i].clear();
        if (a[i] > mx)
            continue;
        pt.push_back(i);
        for (int j : g[i])
            if (a[j] <= mx)
                sg[i].push_back(j), ++in[j];
    }

    memset(mk, 0, sizeof mk);

    queue<int> q;
    for (int i : pt)
        if (!in[i])
            q.push(i), mk[i] = 1;

    while (q.size())
    {
        int u = q.front();
        q.pop();

        for (int v : sg[u])
        {
            mk[v] = max(mk[v], mk[u] + 1);
            if (mk[v] >= k)
                return true;
            if (--in[v] == 0)
                q.push(v);
        }
    }

    for (int i : pt)
        if (in[i])
            return true;
    return false;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }

    int ans = 2e9;

    if (m == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (k <= a[i])
            {
                int res = ceil(a[i] * 1.0 / k);
                if (res < ans)
                    ans = res;
            }
        }
    }
    else
    {
        int l = 1, r = 1e9;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (istok(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
    }

    printf("%d\n", (ans == 2e9) ? -1 : ans);
    return 0;
}
