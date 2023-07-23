#include <cstdio>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

// Node

const int N = 8e4 + 10;

struct node
{
	int a[9];
	int go, p;
} n[N];

int father[N];

// Cantor

int fact[8] = {0, 5040, 720, 120, 24, 6, 2, 1};

int cantor(int x)
{
	int sum = 0, k;
	for (int i = 1 ; i < 8 ; ++i)
	{
		k = 0;
		for (int j = i + 1 ; j <= 8 ; ++j)
			if (n[x].a[j] < n[x].a[i])
				++k;
		sum += k * fact[i];
	}
	return sum;
}

// Queue

int cnt = 1;

unordered_map<int, bool> visit;

// Swap

void A(int x)
{
	for (int i = 1 ; i <= 4 ; ++i)
		swap(n[x].a[i], n[x].a[i + 4]);
}

void B(int x)
{
	int *t = n[x].a;
	swap(*(t + 4), *(t + 3));
	swap(*(t + 8), *(t + 7));
	swap(*(t + 3), *(t + 2));
	swap(*(t + 7), *(t + 6));
	swap(*(t + 2), *(t + 1));
	swap(*(t + 6), *(t + 5));
}

void C(int x)
{
	int *t = n[x].a;
	swap(*(t + 2), *(t + 3));
	swap(*(t + 2), *(t + 7));
	swap(*(t + 2), *(t + 6));
}

void S(int x, int k)
{
	if (k == 1)
		A(x);
	else if (k == 2)
		B(x);
	else if (k == 3)
		C(x);
}

// Write

void write(int x)
{
	if (x == 1)
		return ;
	write(father[x]);
	putchar(n[x].p + 'A');
}

// Main

int main()
{
	for (int i = 1 ; i <= 4 ; ++i)
	{
		scanf("%d", &n[0].a[i]);
		n[1].a[i] = i;
	}
	for (int i = 8 ; i >= 5 ; --i)
	{
		scanf("%d", &n[0].a[i]);
		n[1].a[13 - i] = i;
	}

	int st = cantor(0);

	if (cantor(1) == st)
	{
		printf("0\n");
		return 0;
	}

	queue<int> q;
	q.push(1);
	n[1].go = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 1 ; i <= 3 ; ++i)
		{
			++cnt;
			for (int j = 1 ; j <= 8 ; ++j)
				n[cnt].a[j] = n[x].a[j];

			S(cnt, i);

			int id = cantor(cnt);
			if (!visit[id])
			{
				visit[id] = 1;
				n[cnt].go = n[x].go + 1;
				n[cnt].p = i - 1;
				father[cnt] = x;

				q.push(cnt);
				if (id == st)
				{
					printf("%d\n", n[cnt].go);
					write(cnt);
				}
			}
			else
				--cnt;
		}
	}
	return 0;
}
