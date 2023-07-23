#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int hl[N][N];
int hq[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    for (int i = 1; i <= n; ++i)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= m; ++j)
            hl[i][j] = (hl[i][j - 1] << 1) | (line[j - 1] - '0');
    }

    int q;
    cin >> q;

    while (q--)
    {
        for (int i = 1; i <= a; ++i)
        {
            string line;
            cin >> line;

            hq[i] = 0;
            for (char j : line)
                hq[i] = (hq[i] << 1) | (j - '0');
        }

        bool ans = false;
        for (int ls = 1; !ans && ls <= n - a + 1; ++ls)
        {
            for (int cs = 1; !ans && cs <= m - b + 1; ++cs)
            {
                bool flag = true;
                for (int i = 1; !ans && i <= a; ++i)
                {
                    if (hq[i] != hl[i + ls - 1][cs + b - 1] & (1 << b) - 1)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    ans = true;
            }
        }

        cout << ans << endl;
    }

    fclose(stdin);
    return 0;
}
