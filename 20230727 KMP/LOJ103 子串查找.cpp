#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int ne[N];

void init(string p)
{
    ne[0] = -1;
    for (int j = 0, k = -1; j < p.size();)
    {
        if (k == -1 || p[j] == p[k])
            ne[++j] = ++k;
        else
            k = ne[k];
    }
}

int kmp(string s, string p)
{
    int res = 0;

    int i = 0, j = 0;
    while (i < s.size())
    {
        if (j == -1 || s[i] == p[j])
            ++i, ++j;
        else
            j = ne[j];

        if (j == p.size())
            ++res;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, p;
    cin >> s >> p;

    init(p);
    cout << kmp(s, p) << endl;

    return 0;
}
