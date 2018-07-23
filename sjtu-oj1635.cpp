#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdint.h>

using namespace std;

struct node
{
	int no;
	int val;
	node *next;
	node()
		:no(0), val(0), next(NULL) {}
	node(int n, int v)
		:no(n), val(v), next(NULL) {}
};
struct Pair
{
	int no;
	int dis;
	Pair()
		:no(0), dis(INT32_MAX) {}
};

void downgo(int x, Pair* pq, int* id, int pqsize)
{
	while (x << 1 <= pqsize)
	{
		if ((x << 1) + 1 > pqsize)
		{
			if (pq[x << 1].dis < pq[x].dis)
			{
				id[pq[x].no] = x << 1;
				id[pq[x << 1].no] = x;
				Pair tmp = pq[x << 1];
				pq[x << 1] = pq[x];
				pq[x] = tmp;
				x = x << 1;
			}
			else break;
		}
		else
		{
			int l_r;
			if (pq[x << 1].dis < pq[(x << 1) + 1].dis) l_r = x << 1;
			else l_r = (x << 1) + 1;
			if (pq[l_r].dis < pq[x].dis)
			{
				id[pq[x].no] = l_r;
				id[pq[l_r].no] = x;
				Pair tmp = pq[l_r];
				pq[l_r] = pq[x];
				pq[x] = tmp;
				x = l_r;
			}
			else break;
		}
	}
}

void upgo(int x, Pair* pq, int* id)
{
	while (x > 1 && pq[x >> 1].dis > pq[x].dis)
	{
		id[pq[x].no] = x >> 1;
		id[pq[x >> 1].no] = x;
		Pair tmp = pq[x];
		pq[x] = pq[x >> 1];
		pq[x >> 1] = tmp;
		x = x >> 1;
	}
}

void Pop_pq(Pair* pq, int* id, int &pqsize)
{
	id[pq[1].no] = pqsize;
	id[pq[pqsize].no] = 1;
	pq[1] = pq[pqsize];
	pqsize--;
	downgo(1, pq, id, pqsize);
}

int main()
{
	int n, m;
	cin >> n >> m;
	node *g = new node[n + 1];
	for (int i = 1; i <= n; i++) g[i].no = i;
	int u, v, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		node *tmp = g[u].next;
		g[u].next = new node(v, c);
		g[u].next->next = tmp;
		tmp = g[v].next;
		g[v].next = new node(u, c);
		g[v].next->next = tmp;
	}
	bool *flag = new bool[n + 1];
	for (int i = 1; i <= n; i++) flag[i] = false;
	Pair *pq = new Pair[n + 1];
	int pqsize = n;
	int *id = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		pq[i].no = i;
		id[i] = i;
	}
	pq[1].dis = 0;
	flag[1] = true;
	while (!flag[n])
	{
		node *tmp = g[pq[1].no].next;
		int shortest = pq[1].dis;

		//cout << pq[1].no << endl;

		Pop_pq(pq, id, pqsize);
		while (tmp)
		{
			if (!flag[tmp->no])
			{
				if (shortest + tmp->val < pq[id[tmp->no]].dis)
				{
					pq[id[tmp->no]].dis = shortest + tmp->val;
					upgo(id[tmp->no], pq, id);
				}
			}
			tmp = tmp->next;
		}
		flag[pq[1].no] = true;

		//for (int i = 1; i <= pqsize; i++)
		//	cout << pq[i].no << ":" << pq[i].dis << " ";
		//cout << endl;

	}
	cout << pq[1].dis << endl;
	return 0;
}