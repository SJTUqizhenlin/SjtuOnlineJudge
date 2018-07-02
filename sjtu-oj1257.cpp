#include <stdio.h>

using namespace std;

struct node
{
	node *p;
	node *l;
	node *r;
	bool isExist;
	node() :p(nullptr), l(nullptr), r(nullptr), isExist(0) {}
};

node arr[100005];

void trav(node* n)
{
	printf("%d ", n - arr);
	if (n->l) trav(n->l);
	if (n->r) trav(n->r);
	return;
}

int main()
{
	arr[1].isExist = 1;
	int m;
	scanf("%d", &m);
	int order, o1, o2, o3;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &order);
		if (order == 1)
		{
			scanf("%d%d%d", &o1, &o2, &o3);
			if (arr[o1].isExist == 0 || arr[o1].l || arr[o1].r)
			{
				printf("Error!\n");
				continue;
			}
			if (arr[o2].isExist || arr[o3].isExist || o2 == o3)
			{
				printf("Error!\n");
				continue;
			}
			printf("Ok!\n");
			arr[o1].l = &arr[o2];
			arr[o1].r = &arr[o3];
			arr[o2].p = &arr[o1];
			arr[o3].p = &arr[o1];
			arr[o2].isExist = 1;
			arr[o3].isExist = 1;
		}
		if (order == 2)
		{
			scanf("%d", &o1);
			if (arr[o1].isExist == 0)
			{
				printf("Error!\n");
				continue;
			}
			printf("%d %d %d\n", (arr[o1].p ? arr[o1].p - arr : 0), (arr[o1].l ? arr[o1].l - arr : 0), (arr[o1].r ? arr[o1].r - arr : 0));
		}
		if (order == 3)
		{
			scanf("%d", &o1);
			if (arr[o1].isExist == 0 || o1 == 1)
			{
				printf("Error!\n");
				continue;
			}
			node *tmp = arr[o1].p;
			if (&arr[o1] == tmp->l)
				printf("%d\n", tmp->r - arr);
			else
				printf("%d\n", tmp->l - arr);
			node *mid = tmp->l;
			tmp->l = tmp->r;
			tmp->r = mid;
		}
	}
	trav(&arr[1]);
	printf("\n");
	return 0;
}