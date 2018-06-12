#include <stdio.h>

using namespace std;

struct node
{
	int n;
	node *next;
	node() :n(0), next(nullptr) {}
	node(int nn) :n(nn), next(nullptr) {}
};

void dfs(int x, int* time, int* flag, node* gph)
{
	node* tmp = gph[x].next;
	while (tmp)
	{
		if (!flag[tmp->n]) dfs(tmp->n, time, flag, gph);
		if (time[tmp->n] >= time[x]) time[x] = time[tmp->n] + 1;
		tmp = tmp->next;
	}
	if (!time[x]) time[x] = 1;
	flag[x] = 1;
	return;
}

int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	node* gph = new node[n + 1];
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		node* newnode = new node(a);
		newnode->next = gph[b].next;
		gph[b].next = newnode;
	}
	int *flag = new int[n + 1];
	for (int i = 1; i <= n; i++) flag[i] = 0;
	int res = 0;
	int *time = new int[n + 1];
	for (int i = 1; i <= n; i++) time[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])
			dfs(i, time, flag, gph);
		if (time[i] > res) res = time[i];
	}
	printf("%d\n", res);
	return 0;
}