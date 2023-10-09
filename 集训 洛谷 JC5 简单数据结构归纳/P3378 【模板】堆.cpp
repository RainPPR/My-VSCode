#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	priority_queue< int, vector<int>, greater<int> > Q;

	int n, op, x;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &x);
			Q.push(x);
		}
		else if (op == 2)
			printf("%d\n", Q.top());
		else
			Q.pop();
	}

	return 0;
}
