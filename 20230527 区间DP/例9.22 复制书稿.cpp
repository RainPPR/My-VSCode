#include <cstdio>

using namespace std;

const int N = 510;

int m, k;
int w[N], L[N], R[N];

bool check(int sum)
{
	int s = 0, cnt = 1;

	R[cnt] = m;
	for (int i = m; i; i--)
	{
		if (s + w[i] <= sum)
			s += w[i];
		else
		{
			L[cnt] = i + 1;
			cnt ++;
			R[cnt] = i;
			s = w[i];
		}
	}
	L[cnt] = 1;

	return cnt <= k;
}

int main()
{
	scanf("%d %d", &m, &k);

	int l = 0, r = 1e9;
	for (int i = 1 ; i <= m ; i++)
	{
		scanf("%d", w + i);

		if (w[i] > l)
			l = w[i];
	}

	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}

	check(r);

	for (int i = k ; i > 0 ; i--)
		printf("%d %d\n", L[i], R[i]);
	return 0;
}
