#include <bits/stdc++.h>

using namespace std;

const int mod1 = 1e6 + 3, p1 = 47;
const int mod2 = 1e6 + 9, p2 = 79;
const int N = 30000;

int n;
int e[mod1 + 5], ne[N + 10], ed[N + 10], tot = 0;

void insert(int x, int y)
{
    ne[++tot] = e[x];
    e[x] = tot;
    ed[tot] = y;
}

int query(int x, int y)
{
    for (int i = e[x]; i; i = ne[i])
        if (ed[i] == y)
            return 1;
    return 0;
}

int main()
{
    cin >> n;

    while (n--)
    {
        string op, s;
        cin >> op;
        getline(cin, s);

        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            sum1 = (sum1 * p1 + s[i]) % mod1;
            sum2 = (sum2 * p2 + s[i]) % mod2;
        }

        if (op[0] == 'a')
            insert(sum1, sum2);
        else
            cout << (query(sum1, sum2) ? "yes" : "no") << endl;
    }

    return 0;
}
