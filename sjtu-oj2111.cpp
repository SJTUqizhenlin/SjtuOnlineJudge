#include <stdio.h>

using namespace std;

struct Splay
{
	struct node
	{
		int key;
		node *p, *s[2];
		node()
		{
			p = s[0] = s[1] = nullptr;
			key = 0;
		}
		node(int x)
			:key(x)
		{
			p = s[0] = s[1] = nullptr;
		}
		bool getlr()
		{
			return p->s[1] == this;
		}
		node* link(int w, node* n)
		{
			s[w] = n;
			if (n) n->p = this;
			return this;
		}
	};
	node *root;
	Splay() { root = nullptr; }
	void rot(node *n)
	{
		node *g = n->p->p;
		n->getlr() ? n->link(0, n->p->link(1, n->s[0])) : n->link(1, n->p->link(0, n->s[1]));
		if (g) g->link(g->s[1] == n->p, n);
		else { n->p = nullptr; root = n; }
	}
	void splay(node *n, node *tar)
	{
		while (n->p != tar && n->p->p != tar)
			n->getlr() == n->p->getlr() ? (rot(n->p), rot(n)) : (rot(n), rot(n));
		if (n->p != tar) rot(n);
	}
	node* find(int x)
	{
		node *cur = root;
		while (cur && cur->key != x)
			cur = cur->s[cur->key < x];
		if (cur) splay(cur, nullptr);
		return cur;
	}
	void insert(int x)
	{
		if (!root) { root = new node(x); return; }
		node *cur = root;
		node *pre;
		while (cur)
		{
			pre = cur;
			cur = cur->s[cur->key < x];
		}
		cur = new node(x);
		pre->link(pre->key < x, cur);
		splay(cur, nullptr);
	}
	node* pred()
	{
		node* cur = root->s[0];
		if (!cur) return nullptr;
		while (cur->s[1]) cur = cur->s[1];
		splay(cur, nullptr);
		return cur;
	}
	node* succ()
	{
		node* cur = root->s[1];
		if (!cur) return nullptr;
		while (cur->s[0]) cur = cur->s[0];
		splay(cur, nullptr);
		return cur;
	}
	void del(int l, int r)
	{
		if (!find(l)) insert(l);
		node *low = pred();
		if (!find(r)) insert(r);
		node *upp = succ();
		if (!low && !upp) { root = nullptr; return; }
		if (!low) { root->s[0] = nullptr; return; }
		if (!upp) { splay(low, nullptr); root->s[1] = nullptr; return; }
		splay(low, upp);
		low->s[1] = nullptr;
	}
};

Splay::node* r_bound(int x, Splay::node* root)
{
	if (root->key > x)
	{
		if (!root->s[0]) return root;
		else
		{
			Splay::node* l_res = r_bound(x, root->s[0]);
			if (l_res && l_res->key < root->key) return l_res;
			else return root;
		}
	}
	if (!root->s[1]) return nullptr;
	else
	{
		Splay::node* r_res = r_bound(x, root->s[1]);
		return r_res;
	}
}

Splay::node* l_bound(int x, Splay::node* root)
{
	if (root->key < x)
	{
		if (!root->s[1]) return root;
		else
		{
			Splay::node* r_res = l_bound(x, root->s[1]);
			if (r_res && r_res->key > root->key) return r_res;
			else return root;
		}
	}
	if (!root->s[0]) return nullptr;
	else
	{
		Splay::node* l_res = l_bound(x, root->s[0]);
		return l_res;
	}
}

int main()
{
	Splay tr;
	int M;
	scanf("%d", &M);
	int order;
	int onum;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &order, &onum);
		if (order == 1)
			tr.insert(onum);
		if (order == 2)
			tr.del(onum, onum);
		if (order == 0)
		{
			if (tr.find(onum)) printf("0\n");
			else
			{
				Splay::node* l_b = l_bound(onum, tr.root);
				Splay::node* r_b = r_bound(onum, tr.root);
				if (l_b && r_b)
				{
					if (onum - l_b->key < r_b->key - onum)
						printf("%d\n", onum - l_b->key);
					else printf("%d\n", r_b->key - onum);
					tr.splay(l_b, nullptr);
					tr.splay(r_b, nullptr);
				}
				else
				{
					if (l_b) { printf("%d\n", onum - l_b->key); tr.splay(l_b, nullptr); }
					else { printf("%d\n", r_b->key - onum); tr.splay(r_b, nullptr); }
				}
			}
		}
	}
	return 0;
}