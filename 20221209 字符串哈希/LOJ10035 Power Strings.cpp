#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        string str;
        cin >> str;

        if (str == ".")
            break;

        int n = str.size();

        int ans = n;
        for (int i = 1; i < n; ++i)
        {
            if (n % i)
                continue;

            bool flag = true;
            string tar = str.substr(0, i);
            for (int j = i; j < n; j += i)
            {
                if (str.substr(j, i) != tar)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                ans = i;
                break;
            }
        }

        cout << n / ans << endl;
    }

    return 0;
}