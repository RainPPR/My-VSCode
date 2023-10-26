#include <cstdio>

using namespace std;

const int N = 1010;

int n, q;
int dad[N];

int main()
{
	scanf("%d %d", &n, &q);
	
	int x, y;
	for (int i = 1 ; i <= n - 1 ; ++i)
	{
		scanf("%d %d", &x, &y);
		dad[x] = y;
	}
	
	while (q--)
	{
		scanf("%d %d", &x, &y);
		
		bool ans = false;
		while (y)
		{
			if (x == dad[y])
			{
				ans = true;
				break;
			}
			y = dad[y];
		}
		
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
