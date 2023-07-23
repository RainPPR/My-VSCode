#include <bits/stdc++.h>

using namespace std;

unordered_set<string> dict;

int main()
{
    int n;
    scanf("%d", &n);

    string str;
    for (int i = 0 ; i < n ; ++i)
        cin >> str, dict.insert(str);
    
    int ans = 0;
    while (cin >> str)
        ans += !dict.count(str);

    printf("%d", n);
    return 0;
}
