#include <stdio.h>
using namespace std;

struct node
{
	int no, l, r, p;
	node():no(0),l(0),r(0),p(0) {}
};

node arr[200000];

int getLCA(int root, int x, int y)
{
	if (root == 0) return 0;
	if (root == x || root == y) return root;
	int l = getLCA(arr[root].l, x, y);
	int r = getLCA(arr[root].r, x, y);
	if (l && r) return root;
	else
	{
		if (l) return l;
		if (r) return r;
		return 0;
	}
}

int main()
{
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d%d", &(arr[i].l), &(arr[i].r));
		if (arr[i].l) arr[arr[i].l].p = i;
		if (arr[i].r) arr[arr[i].r].p = i;
	}
	int rootid = 1;
	while (arr[rootid].p) 
		rootid = arr[rootid].p;
	int res = getLCA(rootid, x, y);
	printf("%d\n", res);
	return 0;
}