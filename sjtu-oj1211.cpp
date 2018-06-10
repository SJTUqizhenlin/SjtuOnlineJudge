#include <stdio.h>

using namespace std;

struct node
{
	node *l;
	node *r;
	node *p;
	int pos;
	node() :l(nullptr), r(nullptr), p(nullptr), pos(0) {}
};

bool isCBT(node *root, int n)
{
	if (root->pos > n) return false;
	if (root->l && root->r)
	{
		root->l->pos = root->pos * 2;
		root->r->pos = root->pos * 2 + 1;
		return isCBT(root->l, n) && isCBT(root->r, n);
	}
	if (root->l)
	{
		root->l->pos = root->pos * 2;
		return isCBT(root->l, n);
	}
	if (root->r)
	{
		root->r->pos = root->pos * 2 + 1;
		return isCBT(root->r, n);
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	node *arr = new node[n + 1];
	int a, b;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		if (a) arr[i].l = &arr[a];
		if (b) arr[i].r = &arr[b];
		if (a) arr[a].p = &arr[i];
		if (b) arr[b].p = &arr[i];
	}
	node *root = &arr[1];
	while (root->p) root = root->p;
	root->pos = 1;
	bool res = isCBT(root, n);
	if (res) printf("Y\n");
	else printf("N\n");
	return 0;
}