#include <bits/stdc++.h>

using namespace std;

const int p = 1e5 + 3;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	printf("%d %d\n", p, p);
	printf("1 2 %d\n", p - n + 2);

	for (int i = 2 ; i < n ; ++i)
		printf("%d %d 1\n", i, i + 1);
	
	m -= n - 1;
	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = i + 2 ; j <= n ; ++j)
		{
			if (--m < 0)
				return 0;
			printf("%d %d 1000000000\n", i, j);
		}
	}
	
	return 0;
}
