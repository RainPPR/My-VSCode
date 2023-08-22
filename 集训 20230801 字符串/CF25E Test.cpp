#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 1e5 + 10;
const int p = 1e9 + 7;

ull pw[N];

string s[3];

ull h[3][N];
int del[3][3];

int get(int l, int r, ull h[])
{
    return l ? (h[r] - h[l - 1] * pw[r - l + 1]) : h[r];
}

int main()
{
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * p;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> s[0] >> s[1] >> s[2])
    {
        memset(del, 0, sizeof del);

        h[0][0] = s[0][0];
        for (int i = 1; i < s[0].size(); ++i)
            h[0][i] = h[0][i - 1] * p + s[0][i];

        h[1][0] = s[1][0];
        for (int i = 1; i < s[1].size(); ++i)
            h[1][i] = h[1][i - 1] * p + s[1][i];

        h[2][0] = s[2][0];
        for (int i = 1; i < s[2].size(); ++i)
            h[2][i] = h[2][i - 1] * p + s[2][i];

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == j)
                    continue;

                if (s[i].size() >= s[j].size())
                {
                    int hj = get(0, s[j].size() - 1, h[j]);
                    for (int k = 0; k < s[i].size() - s[j].size(); ++k)
                    {
                        if (get(k, k + s[j].size() - 1, h[i]) == hj)
                        {
                            del[i][j] = -1;
                            break;
                        }
                    }
                }

                if (del[i][j] == -1)
                    continue;

                for (int len = min(s[i].size(), s[j].size()); len; --len)
                {
                    if (get(s[i].size() - len, s[i].size() - 1, h[i]) == get(0, len - 1, h[j]))
                    {
                        del[i][j] = len;
                        break;
                    }
                }
            }
        }

        int res, ans = 2e9;

        for (int a = 0; a < 3; ++a)
        {
            for (int b = 0; b < 3; ++b)
            {
                if (a == b)
                    continue;
                int c = 3 - a - b;

                if (del[a][b] == -1 & del[b][c] == -1)
                    res = s[a].size();
                else if (del[a][b] == -1)
                    res = s[a].size() + s[c].size() - del[a][c];
                else if (del[b][c] == -1)
                    res = s[a].size() + s[b].size() - del[a][b];
                else
                    res = s[a].size() + s[b].size() + s[c].size() - del[a][b] - del[b][c];

                if (res < ans)
                    ans = res;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
