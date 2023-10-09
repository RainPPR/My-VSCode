// generate£ºÉú³ÉÆ÷
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

// [l, r] random number
int rnd(int l, int r)
{
	return (long long) rand() * rand() % (r - l + 1) + l;
}

int main()
{
	srand(time(0));
	freopen("ab.in", "w", stdout);
	int a = rnd(1, 150), b = rnd(1, 150);
	printf("%d %d", a, b);
	return 0;
}
