#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int main()
{
	int n, pos;
	string s1, s2;

	cin >> n >> s1 >> pos;
	s2 = s1;

	char tar = s1[pos - 1];
	sort(s2.begin(), s2.end());

	int now = pos;
	for (int i = 0; i < n; ++i)
	{
		if (s2[i] == tar)
		{
			now = i;
			s2[i] = '.';
			break;
		}
	}

	vector<char> ans;
	ans.push_back(s1[now]);

	for (int i = 1 ; i < n ; ++i)
	{
		for (int j = n - 1 ; j >= 0 ; --j)
		{
			if (s2[j] == s1[now])
			{
				now = j;
				ans.push_back(s1[now]);
				s2[j] = '.';
				break;
			}
		}
	}

	for (int i = n - 1 ; i >= 0 ; --i)
		putchar(ans[i]);
	return 0;
}
