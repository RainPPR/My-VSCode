#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 65;

int fp[N], fpn[N];

signed main()
{
    int n;
    string s;
    cin >> n >> s;

    fp[0] = fpn[0] = 1;
    for (int i = 1; i < s.size(); ++i)
        fp[i] = fp[i - 1] * 10, fpn[i] = fpn[i - 1] * n;

    int ans = 0;
    for (int i = s.size() - 1, cnt = 0; i >= 0; --i)
    {
        int j = i - 1;
        int cur = s[i] - '0';
        while (j >= 0)
        {
            if ((s[j] - '0') * fp[i - j] + cur >= n || i - j + 1 >= 10)
                break;
            cur = (s[j] - '0') * fp[i - j] + cur;
            j--;
        }
        ++j;
        while (s[j] == '0' && j < i)
            ++j;
        ans += cur * fpn[cnt];
        cnt++;
        i = j;
    }

    cout << ans << endl;
    return 0;
}
