#include <cstdio>

const int N = 1e6 + 10;

int le[N], rt[N];
int n;

void f1(int x)
{
	if (x == 0)
		return ;
	printf("%d ", x);
	f1(le[x]);
	f1(rt[x]);
}

void f2(int x)
{
	if (x == 0)
		return ;
	f2(le[x]);
	printf("%d ", x);
	f2(rt[x]);
}

void f3(int x)
{
	if (x == 0)
		return ;
	f3(le[x]);
	f3(rt[x]);
	printf("%d ", x);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d %d", le + i, rt + i);

	f1(1);
	putchar('\n');

	f2(1);
	putchar('\n');

	f3(1);
	putchar('\n');
	return 0;
}
