#include <cstdio>

const int N = 300;

int le[N], rt[N];
int n;

void dfs(int x)
{
	if (x == '*')
		return ;

	printf("%c", x);
	dfs(le[x]);
	dfs(rt[x]);
}

int main()
{

	scanf("%d", &n);

	char str[4];
	scanf("%s", str);
	char root = str[0];
	le[(int)str[0]] = str[1];
	rt[(int)str[0]] = str[2];

	for (int i = 1 ; i < n ; ++i)
	{
		scanf("%s", str);
		le[(int)str[0]] = str[1];
		rt[(int)str[0]] = str[2];
	}

	dfs(root);

	return 0;
}
