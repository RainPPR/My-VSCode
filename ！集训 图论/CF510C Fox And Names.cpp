#include <bits/stdc++.h>

using namespace std;

const int N = 500;

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
	for (int i = 0 ; i <= 26 ; ++i)
		if (!in[i])
			ze.push(i), ans += 'a' + i;

	while (ze.size())
	{
		int now = ze.front();
		ze.pop();

		for (int i = h[now] ; i != -1 ; i = ne[i])
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(h, -1, sizeof h);
	string last;

	cin >> n;
	cin >> last;

	for (int i = 1 ; i < n ; ++i)
	{
		string str;
		cin >> str;

		bool flag = true;
		for (int i = 0 ; i < min(last.size(), str.size()) ; ++i)
		{
			if (last[i] != str[i])
			{
				add(last[i] - 'a', str[i] - 'a');
				flag = false;
				break;
			}
		}

		if (flag && last.size() > str.size())
		{
			cout << "Impossible" << endl;
			return 0;
		}

		last = str;
	}

	for (int i = 0 ; i < 26 ; ++i)
		add(26, i);

	string ans = topsort();
	cout << ((ans.size() < 27) ? "Impossible" : ans.substr(1, 26)) << endl;
	return 0;
}
