#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, x;

	scanf("%d", &n);
	n = 1 << n;

	queue<pair<int, int>> q;
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", &x);
		q.push({x, i});
	}

	pair<int, int> p1, p2;
	while (q.size() > 2)
	{
		p1 = q.front();
		q.pop();
		p2 = q.front();
		q.pop();

		if (p1.first > p2.first)
			q.push(p1);
		else
			q.push(p2);
	}

	p1 = q.front();
	q.pop();
	p2 = q.front();
	q.pop();

	if (p1.first > p2.first)
		printf("%d", p2.second);
	else
		printf("%d", p1.second);

	return 0;
}
