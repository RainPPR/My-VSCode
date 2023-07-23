#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> h;

int main()
{
	int p, t;
	int a, b, c, d;
	scanf("%d %d %d %d %d %d", &p, &t, &a, &b, &c, &d);

	for (int x1 = -t; x1 <= t; ++x1)
		for (int x2 = -t; x2 <= t; ++x2)
			++h[p - a * x1 - b * x2];

	long long ans = 0;
	for (int x3 = -t; x3 <= t; ++x3)
		for (int x4 = -t; x4 <= t; ++x4)
			if (h.count(c * x3 + d * x4))
				ans += h[c * x3 + d * x4];

	printf("%lld\n", ans);
	return 0;
}
