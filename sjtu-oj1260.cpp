#include <stdio.h>

using namespace std;

struct Splaytr
{
	struct node
	{
		int val, size; node *p, *s[2];
		node() { val = 0; size = 1; p = s[0] = s[1] = nullptr; }
		node(int vval) { val = vval; size = 1; p = s[0] = s[1] = nullptr; }
		bool getlr() { return (this == p->s[1]); }
		node* link(int w, node *n) { s[w] = n; if (n) n->p = this; return this; }
		void update() { size = 1 + (s[0] ? s[0]->size : 0) + (s[1] ? s[1]->size : 0); return; }
	};
	node *root;
	Splaytr() :root(nullptr) {}
	void rot(node *n)
	{
		node *q = n->p->p;
		n->getlr() ? n->link(0, n->p->link(1, n->s[0])) : n->link(1, n->p->link(0, n->s[1]));
		n->p->update();
		if (q) q->link(n->p == q->s[1], n);
		else { n->p = nullptr; root = n; }
	}
	void splay(node *n, node *tar)
	{
		while (n->p != tar && n->p->p != tar)
			n->getlr() == n->p->getlr() ? (rot(n->p), rot(n)) : (rot(n), rot(n));
		if (n->p != tar) rot(n);
		n->update();
	}
	void insert(int k, int v)
	{
		if (!root) { root = new node(v); return; }
		node *cur = root;
		while (k > 0 && k < cur->size)
		{
			int midsize = (cur->s[0] ? cur->s[0]->size : 0) + 1;
			if (k < midsize) cur = cur->s[0];
			else { cur = cur->s[1]; k -= midsize; }
		}
		if (k == 0)
		{
			while (cur->s[0]) cur = cur->s[0];
			node *tmp = new node(v); cur->link(0, tmp);
			splay(tmp, nullptr);
		}
		else
		{
			while (cur->s[1]) cur = cur->s[1];
			node *tmp = new node(v); cur->link(1, tmp);
			splay(tmp, nullptr);
		}
		return;
	}
	void trav(node* n)
	{
		if (n->s[0]) trav(n->s[0]);
		printf("%d ", n->val);
		if (n->s[1]) trav(n->s[1]);
		return;
	}
};

int main()
{
	int N; scanf("%d", &N);
	Splaytr tr1;
	int pos, val;
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &pos, &val);
		tr1.insert(pos, val);
	}
	tr1.trav(tr1.root); printf("\n");
	return 0;
}