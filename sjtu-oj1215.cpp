#include <stdio.h>
using namespace std;

int pq[30000], pqsize = 0;
int M; char Order[10];

void exchange(int id1, int id2)
{
	int tmp = pq[id1];
	pq[id1] = pq[id2];
	pq[id2] = tmp; return;
}

void pq_push()
{
	int i = pqsize;
	while (i > 1)
	{
		if (pq[i / 2] > pq[i])
		{
			exchange(i, i / 2);
			i = i / 2;
		}
		else break;
	}
	return;
}

void pq_pop()
{
	exchange(1, pqsize);
	pqsize--;
	int i = 1;
	while (i * 2 <= pqsize)
	{
		int minid = i * 2;
		if (i * 2 + 1 <= pqsize && pq[i * 2 + 1] < pq[i * 2])
			minid = i * 2 + 1;
		if (pq[minid] < pq[i])
		{
			exchange(i, minid);
			i = minid;
		}
		else break;
	}
	return;
}

int main()
{
	scanf("%d", &M); int tmp;
	for (int i = 0; i < M; i++)
	{
		scanf("%s", Order);
		if (Order[0] == 'i')
		{
			scanf("%d", &tmp);
			pq[++pqsize] = tmp;
			pq_push();
		}
		if (Order[0] == 'd')
		{
			pq_pop();
		}
		if (Order[0] == 'm')
		{
			printf("%d\n", pq[1]);
		}
	}
	return 0;
}