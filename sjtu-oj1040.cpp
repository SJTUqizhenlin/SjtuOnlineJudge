#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

struct node
{
	int no;
	node *left;
	node *right;
	node()
	{
		no = -1;
		left = NULL;
		right = NULL;
	}
};

int main()
{
	int n;
	cin >> n;
	node *arr = new node[n];
	arr[0].no = 0;
	int par;
	for (int i = 1; i < n; i++)
	{
		arr[i].no = i;
		scanf("%d", &par);
		if (arr[par].left == NULL)
			arr[par].left = &arr[i];
		else
		{
			if (arr[par].left->no < i)
				arr[par].right = &arr[i];
			else
			{
				arr[par].right = arr[par].left;
				arr[par].left = &arr[i];
			}
		}
	}
	queue<node*> q;
	q.push(&arr[0]);
	node *cur;
	int c = 0;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (c < n - 1) printf("%d ", cur->no);
		else printf("%d", cur->no);
		c++;
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
	cout << endl;
	return 0;
}