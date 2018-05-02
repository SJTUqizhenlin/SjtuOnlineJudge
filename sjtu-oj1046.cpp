#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int val;
	int no;
	int rank;
	int paint;
	node *left;
	node *right;
	node *left_bound;
	node *right_bound;
	node *parent;
	node() :val (0), no(0), rank(0), paint(0), left(NULL), right(NULL), left_bound(NULL), right_bound(NULL), parent(NULL) {}
};

int main()
{
	int n, p, q;
	scanf("%d%d%d", &n, &p, &q);
	node* *nodearr = new node*[n];
	for (int i = 0; i < n; i++)
	{
		nodearr[i] = new node();
		nodearr[i]->no = i;
	}
	int x, Lx, Rx;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &x, &Lx, &Rx);
		if (Lx != 0)
		{
			nodearr[x - 1]->left = nodearr[Lx - 1];
			nodearr[Lx - 1]->parent = nodearr[x - 1];
		}
		if (Rx != 0)
		{
			nodearr[x - 1]->right = nodearr[Rx - 1];
			nodearr[Rx - 1]->parent = nodearr[x - 1];
		}
	}
	
	node *tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = nodearr[i];
		while (tmp->left != NULL) tmp = tmp->left;
		nodearr[i]->left_bound = tmp;
		tmp = nodearr[i];
		while (tmp->right != NULL) tmp = tmp->right;
		nodearr[i]->right_bound = tmp;
	}
	
	stack<node*> nodestack;
	node* *trav_node = new node*[n];
	node *root = nodearr[0];
	while (root->parent != NULL) root = root->parent;
	node *pCur = root;
	int count = 0;
	while (pCur != NULL || !nodestack.empty())
	{
		if (pCur->left != NULL)
		{
			nodestack.push(pCur);
			pCur = pCur->left;
		}
		else
		{
			trav_node[count] = pCur;
			pCur->rank = count;
			count++;
			pCur = pCur->right;
		}
		while (pCur == NULL && !nodestack.empty())
		{
			pCur = nodestack.top();
			nodestack.pop();
			trav_node[count] = pCur;
			pCur->rank = count;
			count++;
			pCur = pCur->right;
		}
	}

	int t, x1;
	for (int i = 0; i < p; i++)
	{
		scanf("%d%d", &t, &x1);
		node *begin = trav_node[nodearr[t - 1]->rank]->left_bound;
		node *end = trav_node[nodearr[t - 1]->rank]->right_bound;
		int y = end->rank - begin->rank + 1;
		x1 = x1 % y;
		node *plusnode = trav_node[begin->rank + x1];
		if (plusnode->paint == 0) 
		{ 
			plusnode->val++; 
			plusnode->paint = 1; 
			while (plusnode->parent != NULL)
			{
				plusnode->parent->val++;
				plusnode = plusnode->parent;
			}
		}
	}

	int w;
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &w);
		printf("%d%c", nodearr[w - 1]->val, '\n');
	}
	return 0;
}