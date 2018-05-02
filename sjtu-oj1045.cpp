#include <iostream>
#include <stdio.h>

using namespace std;

int a[200001];
int c[200001];
int f[200001];

int main()
{
	a[1] = 1;
	c[0] = 1;
	int N;
	cin >> N;
	char situ;
	int p1, p2;
	int count = 1;
	for (int i = 0; i < N; i++)
	{
		scanf("%c", &situ);
		scanf("%c", &situ);
		if (situ == 'B')
		{
			scanf("%d%d", &p1, &p2);
			a[p2] = 1;
			f[p2] = p1;
			c[p1]++;
		}
		if (situ == 'D')
		{
			scanf("%d", &p1);
			a[p1] = 0;
			if (a[f[p1]]) c[f[p1]]--;
			if (a[f[p1]]) count += c[p1];
			else count += (c[p1] - 1);
			printf("%d\n", count);
		}
	}
	return 0;
}