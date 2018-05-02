#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	node *parent;
	node() :val(0), left(NULL), right(NULL), parent(NULL) {}
	//node(int v) :val(v),left(NULL),right(NULL),parent(NULL) {}
};

int main()
{
	int n;
	cin >> n;
	node nodearr[1024];
	for (int i = 1; i <= n; i++)
	{
		nodearr[i].val = i;
	}
	int a, b, c;
	while (cin >> a)
	{
		cin >> b >> c;
		nodearr[a].left = &nodearr[b];
		nodearr[a].right = &nodearr[c];
		nodearr[b].parent = &nodearr[a];
		nodearr[c].parent = &nodearr[a];
	}
	int root = 1;
	while (nodearr[root].parent != NULL)
	{
		root = nodearr[root].parent->val;
	}
	queue<node*> q;
	q.push(&nodearr[root]);
	while (!q.empty())
	{
		cout << q.front()->val << '\n';
		if (q.front()->left != NULL) q.push(q.front()->left);
		if (q.front()->right != NULL) q.push(q.front()->right);
		q.pop();
	}
	return 0;
}