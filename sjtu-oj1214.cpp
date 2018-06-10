#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
	int w;
	node *l;
	node *s;
	node *p;
	node() :w(0), l(nullptr), s(nullptr), p(nullptr) {}
};

void func1(node *root)
{
	printf("%d ", root->w);
	node *cur = root->l;
	while (cur)
	{
		func1(cur);
		cur = cur->s;
	}
}

void func2(node *root)
{
	node *cur = root->l;
	while (cur)
	{
		func2(cur);
		cur = cur->s;
	}
	printf("%d ", root->w);
}

void func3(node *root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		printf("%d ", q.front()->w);
		node *cur = q.front()->l;
		while (cur)
		{
			q.push(cur);
			cur = cur->s;
		}
		q.pop();
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	node *arr = new node[N + 1];
	int a, b, c;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a) arr[i].l = &arr[a];
		if (b) arr[i].s = &arr[b];
		arr[i].w = c;
		if (a) arr[a].p = &arr[i];
		if (b) arr[b].p = &arr[i];
	}
	node *root = &arr[1];
	while (root->p) root = root->p;
	func1(root);
	printf("\n");
	func2(root);
	printf("\n");
	func3(root);
	printf("\n");
	return 0;
}