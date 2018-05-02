#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
	int no;
	node* leftch;
	node* rightsi;
	node* par;
	node* leftsi;
	node()
	{
		no = -1;
		leftch = NULL;
		rightsi = NULL;
		par = NULL;
		leftsi = NULL;
	}
};

void before_tra(node *root)
{
	printf("%d ", root->no);
	node *tmpn;
	if (root->leftch) tmpn = root->leftch; else tmpn = NULL;
	while (tmpn)
	{
		before_tra(tmpn);
		tmpn = tmpn->rightsi;
	}
}

void after_tra(node *root)
{
	node *tmpn;
	if (root->leftch) tmpn = root->leftch; else tmpn = NULL;
	while (tmpn)
	{
		after_tra(tmpn);
		tmpn = tmpn->rightsi;
	}
	printf("%d ", root->no);
}

void order_tra(node *root)
{
	queue<node*> q;
	q.push(root);
	node *tmpn;
	while (!q.empty())
	{
		tmpn = q.front();
		q.pop();
		printf("%d ", tmpn->no);
		node *tmpn0;
		if (tmpn->leftch) tmpn0 = tmpn->leftch; else tmpn0 = NULL;
		while (tmpn0)
		{
			q.push(tmpn0);
			tmpn0 = tmpn0->rightsi;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	node *arr = new node[n + 1];
	for (int i = 1; i <= n; i++)
		arr[i].no = i;
	int a, b, c;
	node *tmpn1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (b != 0) 
		{ 
			arr[a].leftch = &arr[b]; 
			tmpn1 = &arr[b];
			while (tmpn1)
			{
				tmpn1->par = &arr[a];
				tmpn1 = tmpn1->rightsi;
			}
		}
		if (c != 0)
		{
			arr[a].rightsi = &arr[c];
			arr[c].leftsi = &arr[a];
			tmpn1 = &arr[a];
			while (tmpn1->leftsi)
			{
				tmpn1 = tmpn1->leftsi;
			}
			if (tmpn1->par) arr[c].par = tmpn1->par;
		}
	}
	node *root = &arr[1];
	while (root->par) root = root->par;
	before_tra(root);
	cout << endl;
	after_tra(root);
	cout << endl;
	order_tra(root);
	cout << endl;
	return 0;
}