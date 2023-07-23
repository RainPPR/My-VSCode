#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int a[N];
int q[N];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", a + i);

	int st = 0;
	int ed = 1;

	for (int i = 1 ; i <= n ; ++i)
	{
		while (st < ed && q[st] < i - k + 1)
			++st;
		while (st < ed && a[i] < a[q[ed - 1]])
			--ed;
		q[ed++] = i;
		if (i >= k)
			printf("%d ", a[q[st]]);
	}

	putchar('\n');

	st = 0;
	ed = 1;

	for (int i = 1 ; i <= n ; ++i)
	{
		while (st < ed && q[st] < i - k + 1)
			++st;
		while (st < ed && a[i] > a[q[ed - 1]])
			--ed;
		q[ed++] = i;
		if (i >= k)
			printf("%d ", a[q[st]]);
	}

	putchar('\n');
	return 0;
}

