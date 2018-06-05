#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 10005;
int Par[maxn];
int Sum[maxn];
int City[maxn];

void initSet(int n)
{
	for (int i = 1; i <= n; i++)
	{
		Par[i] = i;
		Sum[i] = 1;
		City[i] = 0;
	}
}

int findPar(int x)
{
	if (Par[x] == x) return x;
	int y = Par[x];
	Par[x] = findPar(Par[x]);
	City[x] += City[y];
	return Par[x];
}

void uniteSet(int x, int y)
{
	x = findPar(x);
	y = findPar(y);
	if (x == y) return;
	Par[x] = y;
	Sum[y] += Sum[x];
	City[x] = 1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	initSet(n);
	char order;
	int o1, o2;
	for (int i = 0; i < m; i++)
	{
		scanf("\n%c", &order);
		if (order == 'T')
		{
			scanf("%d%d", &o1, &o2);
			uniteSet(o1, o2);
		}
		if (order == 'Q')
		{
			scanf("%d", &o1);
			printf("%d ", findPar(o1));
			printf("%d ", Sum[findPar(o1)]);
			printf("%d\n", City[o1]);
		}
	}
	return 0;
}