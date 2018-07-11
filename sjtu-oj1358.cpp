#include <stdio.h>
using namespace std;

int N;
struct trnode
{
	int no, size;
	trnode* next;
	trnode() :no(0), size(1), next(nullptr) {}
	trnode(int nno) :no(nno), size(1), next(nullptr) {}
};
trnode *trarr;
bool *visited;

void getSizeAround(trnode *cur)
{
	visited[cur->no] = 1;
	if (cur->size > 1) return;
	trnode *tmp = trarr[cur->no].next;
	while (tmp)
	{
		if (!visited[tmp->no])
		{
			getSizeAround(tmp);
			cur->size += tmp->size;
		}
		tmp = tmp->next;
	}
	return;
}

int main()
{
	scanf("%d", &N);
	trarr = new trnode[N + 1];
	visited = new bool[N + 1];
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &u, &v);
		trnode *tmpu = new trnode(u), *tmpv = new trnode(v);
		tmpv->next = trarr[u].next;
		trarr[u].next = tmpv;
		tmpu->next = trarr[v].next;
		trarr[v].next = tmpu;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int i = 0; i <= N; i++) visited[i] = 0;
		visited[i] = 1;
		bool isNiceNode = true;
		trnode* cur = trarr[i].next;
		while (cur)
		{
			getSizeAround(cur);
			if (cur->size > N / 2)
			{
				isNiceNode = false;
				break;
			}
			cur = cur->next;
		}
		if (isNiceNode) printf("%d\n", i);
	}
	return 0;
}