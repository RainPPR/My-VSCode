#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010;

string a, b;
int f[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;

	for (int i = 1 ; i <= a.size() ; ++i)
		f[i][0] = i;
	for (int j = 1 ; j <= b.size() ; ++j)
		f[0][j] = j;

	for (int i = 1 ; i <= a.size() ; ++i)
	{
		for (int j = 1 ; j <= b.size() ; ++j)
		{
			f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
			if (a[i - 1] == b[j - 1])
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
		}
	}

	cout << f[a.size()][b.size()] << endl;
	return 0;
}
