#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
	int val;
	node *p, *l, *r;
	node() :val(0), p(nullptr), l(nullptr), r(nullptr) {}
};

int main()
{
	int n, pi, qi, vi; scanf("%d", &n);
	node *bintr = new node[n + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &pi, &qi, &vi);
		if (pi) { bintr[i].l = &bintr[pi]; bintr[pi].p = &bintr[i]; }
		if (qi) { bintr[i].r = &bintr[qi]; bintr[qi].p = &bintr[i]; }
		bintr[i].val = vi;
	}
	node *root = &bintr[1];
	while (root->p) root = root->p;
	queue<node*> q; q.push(root);
	while (!q.empty())
	{
		node *cur = q.front();
		printf("%d ", cur->val);
		if (cur->l) q.push(cur->l);
		if (cur->r) q.push(cur->r);
		q.pop();
	}
	printf("\n");
	return 0;
}