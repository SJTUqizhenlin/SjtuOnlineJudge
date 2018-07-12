#include <stdio.h>
using namespace std;

struct tree_node
{
	int id, leng;
	tree_node *next;
	tree_node() :id(0), next(nullptr) {}
	tree_node(int iid, int lleng) 
		:id(iid), leng(lleng), next(nullptr) {}
};

tree_node tree_arr[10005];
int sonnum[10005];
long long undersum[10005];
long long upsum[10005];
int N, Root;

void dfs1(int root)
{
	sonnum[root] = 0;
	tree_node *cur = tree_arr[root].next;
	while (cur)
	{
		dfs1(cur->id);
		sonnum[root] += (sonnum[cur->id] + 1);
		cur = cur->next;
	}
	return;
}

void dfs2(int root)
{
	undersum[root] = upsum[root] = 0;
	if (sonnum[root] == 0) return;
	tree_node *cur = tree_arr[root].next;
	while (cur)
	{
		dfs2(cur->id);
		undersum[root] += undersum[cur->id];
		undersum[root] += ((upsum[cur->id] + (cur->leng * sonnum[cur->id]) + cur->leng)
			* (sonnum[root] - sonnum[cur->id]));
		upsum[root] += (upsum[cur->id] + (cur->leng * sonnum[cur->id]) + cur->leng);
		cur = cur->next;
	}
	return;
}

int main()
{
	scanf("%d", &N);
	int p, l;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d", &p, &l);
		if (p == 0) Root = i;
		else
		{
			tree_node *tmp = new tree_node(i, l);
			tmp->next = tree_arr[p].next;
			tree_arr[p].next = tmp;
		}
	}
	dfs1(Root);
	dfs2(Root);
	int div = (N * (N - 1)) / 2;
	double res = (double)(undersum[Root]) / div;
	printf("%.2f\n", res);
	return 0;
}

