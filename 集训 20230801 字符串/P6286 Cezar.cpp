#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n;
int h[N], e[N], ne[N], idx;
int in[N];

void add(int u, int v)
{
    ++in[v];
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}

string topsort()
{
    string ans;

    queue<int> ze;
    for (int i = 0; i <= 26; ++i)
        if (!in[i])
            ze.push(i), ans += 'a' + i;

    while (ze.size())
    {
        int now = ze.front();
        ze.pop();

        for (int i = h[now]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (--in[v] == 0)
            {
                ze.push(v);
                ans += 'a' + v;
            }
        }
    }

    return ze.size() ? "Impossible" : ans;
}

string query[N];

string str[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(h, -1, sizeof h);
    string last;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> query[i];

    int rk;
    for (int i = 0; i < n; ++i)
    {
        cin >> rk;
        str[i] = query[rk];
    }

    last = str[0];

    for (int k = 1; k < n; ++k)
    {
        bool flag = true;
        for (int i = 0; i < min(last.size(), str[k].size()); ++i)
        {
            if (last[i] != str[k][i])
            {
                add(last[i] - 'a', str[k][i] - 'a');
                flag = false;
                break;
            }
        }

        if (flag && last.size() > str[k].size())
        {
            cout << "NE" << endl;
            cerr << "WQ1" << endl;
            return 0;
        }

        last = str[k];
    }

    for (int i = 0; i < 26; ++i)
        add(26, i);

    string ans = topsort().substr(1, 26);
    if (ans.size() < 26)
    {
        cout << "NE" << endl;
        cerr << ":[ " << ans << " ]" << endl;
        cerr << "WQ2" << endl;
        return 0;
    }

    string res = ans;
    for (int i = 0; i < 26; ++i)
        res[ans[i] - 'a'] = i + 'a';

    cout << "DA" << endl;
    cout << res << endl;
    return 0;
}
