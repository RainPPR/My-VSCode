#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> PIS;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

const char op[4] = {'u', 'l', 'r', 'd'};

string gend = "123804765";
int tar[9] = {0, 1, 3, 5, 8, 7, 6, 3};

int f(string state)
{
	int res = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (state[i] != '0')
		{
			int t = tar[state[i] - '1'];
			res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
		}
	}
	return res;
}

string a_star(string start, string end = gend)
{
	unordered_map<string, int> dist;
	unordered_map<string, pair<char, string>> prev;
	priority_queue<PIS, vector<PIS>, greater<PIS>> heap;

	dist[start] = 0;
	heap.push({f(start), start});

	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();

		string state = t.second;
		if (state == end)
			break;

		int x, y;
		for (int i = 0; i < 9; ++i)
		{
			if (state[i] == '0')
			{
				x = i / 3, y = i % 3;
				break;
			}
		}

		string source = state;
		for (int i = 0; i < 4; ++i)
		{
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 0 || a > 2 || b < 0 || b > 2)
				continue;
			state = source;
			swap(state[x * 3 + y], state[a * 3 + b]);
			if (!dist.count(state) || dist[state] > dist[source] + 1)
			{
				dist[state] = dist[source] + 1;
				prev[state] = {op[i], source};
				heap.push({dist[state] + f(state), state});
			}
		}
	}

	string res;
	while (end != start)
	{
		res = prev[end].first + res;
		end = prev[end].second;
	}
	return res;
}

int main()
{
	string start;
	cin >> start;
	// 保证可以达到目标
	// int cnt = 0;
	// for (int i = 0 ; i < 9 ; ++i)
	//	if (start[i] != '0')
	//		for (int j = i + 1 ; j < 9 ; ++j)
	//			if (start[j] != '0' && start[i] > start[j])
	//				++cnt;
	// if (cnt & 1 == 0)
	//	cout << "-1" << endl;
	// else
	cout << a_star(start).size() << endl;
	return 0;
}
