#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];

void aset(const int &a, int &s1, int &s2)
{
	if (a > s1)
		s2 = s1, s1 = a;
	else if (a > s2)
		s2 = a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	sort(a, a + n);
	n = unique(a, a + n) - a;

	int s = a[n - 1];

	int a1 = -1, a2 = -1;

	for (int i = 0; i < n - 1; ++i)
	{
		aset(a[i] % s, a1, a2);
		aset(s % a[i], a1, a2);
	}

	printf("%d\n", a2);
	return 0;
}
