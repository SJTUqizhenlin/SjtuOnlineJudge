#include <iostream>
#include <string.h>
using namespace std;

struct node
{
	char c; node *l, *r;
	node(char cc) :c(cc), l(nullptr), r(nullptr) {}
};

char tr_pre[30], tr_mid[30];
char tr[30];

node* cons_tr(int a, int b, int l)
{
	int i; char r = tr_pre[a];
	node *root = new node(r);
	if (l == 1) return root;
	for (i = b; i < b + l; i++)
		if (tr_mid[i] == r) break;
	int llen = i - b; int rlen = l - 1 - llen;
	if (llen) root->l = cons_tr(a + 1, b, llen);
	if (rlen) root->r = cons_tr(a + llen + 1, i + 1, rlen);
	return root;
}

void aft_trav(node *root)
{
	if (root->l) aft_trav(root->l);
	if (root->r) aft_trav(root->r);
	cout << root->c;
	return;
}

int main()
{
	cin >> tr_pre >> tr_mid;
	int trlen = strlen(tr_pre);
	node *Root = cons_tr(0, 0, trlen);
	aft_trav(Root);
	return 0;
}