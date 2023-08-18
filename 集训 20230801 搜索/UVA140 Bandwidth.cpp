#include <bits/stdc++.h>

using namespace std;

const int N = 26;

unordered_set<int> G[N];

int n;

string path;
int ans, pos[N];

void dfs(string now, int res)
{
    if (now.size() == n)
    {
        if (res < ans)
            ans = res, path = now;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (pos[i] || G[i].size() == 0)
            continue;

        int length = 0;
        for (int j : G[i])
        {
            if (!pos[j])
                continue;
            int t = now.size() - pos[j] + 1;
            if (t < 0)
                t = -t;
            if (t > length)
                length = t;
        }

        if (length > ans)
            continue;

        pos[i] = now.size() + 1;
        dfs(now + char(i + 'A'), max(res, length));
        pos[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (cin >> line && line != "#")
    {
        line += ';';

        for (int i = 0; i < N; ++i)
            G[i].clear();

        n = 0;
        int ve[N] = {0};
        for (int i = 0; i < line.size(); ++i)
        {
            char u = line[i];

            if (!ve[u - 'A'])
                ++n;
            ++ve[u - 'A'];

            for (i = i + 2; line[i] != ';'; ++i)
            {
                char v = line[i];

                if (!ve[v - 'A'])
                    ++n;
                ++ve[v - 'A'];

                G[u - 'A'].insert(v - 'A');
                G[v - 'A'].insert(u - 'A');
            }
        }

        ans = n - 1;
        dfs("", 0);

        for (char i : path)
            cout << i << " ";
        cout << "-> " << ans << endl;
    }

    return 0;
}
