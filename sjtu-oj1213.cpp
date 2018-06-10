#include <stdio.h>

using namespace std;

struct node
{
	int val;
	node *p, *l, *r;
	node() :val(0), p(nullptr), l(nullptr), r(nullptr) {}
};

bool is_same(node *root1, node *root2)
{
	if (!root1 || !root2) return (!root1 && !root2);
	return (root1->val == root2->val && is_same(root1->l, root2->l) && is_same(root1->r, root2->r));
}

int main()
{
	int n, m, pi, qi, vi; 
	scanf("%d", &n);
	node *tr1 = new node[n + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &pi, &qi, &vi);
		if (pi) { tr1[i].l = &tr1[pi]; tr1[pi].p = &tr1[i]; }
		if (qi) { tr1[i].r = &tr1[qi]; tr1[qi].p = &tr1[i]; }
		tr1[i].val = vi;
	}
	node *root1 = &tr1[1];
	while (root1->p) root1 = root1->p;
	scanf("%d", &m);
	node *tr2 = new node[m + 1];
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &pi, &qi, &vi);
		if (pi) { tr2[i].l = &tr2[pi]; tr2[pi].p = &tr2[i]; }
		if (qi) { tr2[i].r = &tr2[qi]; tr2[qi].p = &tr2[i]; }
		tr2[i].val = vi;
	}
	node *root2 = &tr2[1];
	while (root2->p) root2 = root2->p;
	if (is_same(root1, root2)) printf("Y\n"); else printf("N\n");
	return 0;
}