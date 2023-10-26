#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

struct Tp
{
	ll t, b, s;
} g[N], l[N];
int gn, ln;

int Z, n, T, t, b;

bool cmp_g(Tp a, Tp b)
{
	return a.t < b.t;
}
bool cmp_l(Tp a, Tp b)
{
	return a.s > b.s;
}

bool check()
{
	ll cur = T;

	sort(g, g + gn, cmp_g);
	for (int i = 0 ; i < gn ; ++i)
	{
		if (cur <= g[i].t)
			return false;
		cur += g[i].b;
	}

	sort(l, l + ln, cmp_l);
	for (int i = 0 ; i < ln ; ++i)
	{
		if (cur <= g[i].t)
			return false;
		cur += g[i].b;
		if (cur <= 0)
			return false;
	}

	return true;
}

int main()
{

	scanf("%d", &Z);
	while (Z--)
	{
		gn = ln = 0;
		scanf("%d %d", &n, &T);
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%d %d", &t, &b);
			if (b >= 0)
				g[gn].t = t, g[gn].b = b, ++gn;
			else
				l[ln].t = t, l[ln].b = b, l[ln].s = t + b, ++ln;
		}

		if (check())
			printf("+1s\n");
		else
			printf("-1s\n");
	}

	return 0;
}
