#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100;

int n, m;
int len, cmax, sum, ext;

int a[N];
bool used[N];

void dfs(int k, int last, int rest)
{
	if (k == m)
	{
		ext = 1;
		return ;
	}

	if (rest == 0)
	{
		int i;
		for (i = 1 ; i <= n ; ++i)
		{
			if (!used[i])
			{
				used[i] = 1;
				break;
			}
		}
		dfs(k + 1, i, len - a[i]);
	}

	for (int i = last + 1 ; i <= n ; ++i)
	{
		if (!used[i] && rest >= a[i])
		{
			used[i] = 1;

			dfs(k, i, rest - a[i]);

			used[i] = 0;

//			int t = a[i];
//			while (i < n && a[i] == t)
//				++i;
//
//			if (i == n)
//				return ;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		cmax = (a[i] > cmax) ? a[i] : cmax;
		sum += a[i];
	}

	sort(a + 1, a + n + 1, [](int a, int b)
	{
		return a > b;
	});

	for (len = cmax ; len <= sum ; ++len)
	{
		if (sum % len == 0)
		{
			memset(used, 0, sizeof used);

			used[1] = 1;
			ext = 0;
			m = sum / len;

			dfs(1, 1, len - a[1]);

			if (ext)
			{
				printf("%d", len);
				break;
			}
		}
	}

	return 0;
}
