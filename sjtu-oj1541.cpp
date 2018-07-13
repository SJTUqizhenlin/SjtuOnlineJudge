#include <stdio.h>

using namespace std;

int arrhp[200005];
int rankofid[200005];
int idofrank[200005];
int heapsize = 0;

void exchange(int rank1, int rank2)
{
	int tmp = arrhp[rank1];
	arrhp[rank1] = arrhp[rank2];
	arrhp[rank2] = tmp;
	tmp = idofrank[rank1];
	idofrank[rank1] = idofrank[rank2];
	idofrank[rank2] = tmp;
	rankofid[idofrank[rank1]] = rank1;
	rankofid[idofrank[rank2]] = rank2;
	return;
}

void pushmyheap()
{
	int p = heapsize;
	while (p > 1)
	{
		if (arrhp[p] <= arrhp[p / 2]) break;
		exchange(p, p / 2);
		p = p / 2;
	}
	return;
}

void delmyheap(int id)
{
	int p = rankofid[id];
	int delta = arrhp[heapsize] - arrhp[p];
	exchange(p, heapsize);
	heapsize--;
	if (delta < 0)
	{
		while (p * 2 <= heapsize)
		{
			int maxind = p * 2;
			if (p * 2 + 1 <= heapsize &&
				arrhp[p * 2 + 1] > arrhp[p * 2]) maxind = p * 2 + 1;
			if (arrhp[maxind] > arrhp[p])
			{
				exchange(p, maxind);
				p = maxind;
			}
			else break;
		}
	}
	if (delta > 0)
	{
		while (p > 1)
		{
			if (arrhp[p] <= arrhp[p / 2]) break;
			exchange(p, p / 2);
			p = p / 2;
		}
	}
	return;
}

int main()
{
	int k, n; scanf("%d%d", &k, &n);
	int arri;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &arri);
		arrhp[++heapsize] = arri;
		rankofid[i] = heapsize;
		idofrank[heapsize] = i;
		pushmyheap();
	}
	printf("%d", arrhp[1]);
	for (int i = k + 1; i <= n; i++)
	{
		delmyheap(i - k);
		scanf("%d", &arri);
		arrhp[++heapsize] = arri;
		rankofid[i] = heapsize;
		idofrank[heapsize] = i;
		pushmyheap();
		printf(" %d", arrhp[1]);
	}
	printf("\n");
	return 0;
}
