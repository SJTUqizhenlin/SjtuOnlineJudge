#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	int N, x, y, z;
	cin >> N;
	map<int, map<int, int>* > store;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (store.find(x) == store.end())
			store.insert(map<int, map<int, int>* >::value_type(x, new map<int, int>));
		(*store[x])[y] = z;
	}
	int curx[100000];
	int cury[100000];
	for (int i = 0; i < 100000; i++)
	{
		curx[i] = i;
		cury[i] = i;
	}
	int M;
	cin >> M;
	int tmpint;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &z, &x, &y);
		if (z == 0)
		{
			tmpint = curx[x];
			curx[x] = curx[y];
			curx[y] = tmpint;
		}
		if (z == 1)
		{
			tmpint = cury[x];
			cury[x] = cury[y];
			cury[y] = tmpint;
		}
		if (z == 2)
		{
			if (store.find(curx[x]) != store.end())
			{
				if (store[curx[x]]->find(cury[y]) != store[curx[x]]->end())
					printf("%d\n", (*store[curx[x]])[cury[y]]);
				else printf("%d\n", 0);
			}
			else printf("%d\n", 0);
		}
	}
	return 0;
}