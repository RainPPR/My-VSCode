#include <iostream>

using namespace std;

const int N = 50010;

int n;
int a[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        a[i] += v;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += a[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int k = 1; k <= T; ++k)
    {
        cout << "Case " << k << ":" << endl;

        cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            int val;
            cin >> val;
            add(i, val);
        }

        while (true)
        {
            string op;
            cin >> op;

            if (op == "End")
                break;

            int i, j;
            cin >> i >> j;

            if (op == "Add")
                add(i, j);
            else if (op == "Sub")
                add(i, -j);
            else if (op == "Query")
                cout << query(j) - query(i - 1) << endl;
        }
    }

    return 0;
}
