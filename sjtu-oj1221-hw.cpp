#include <iostream>
#include <string.h>
#include <stdint.h>

using namespace std;

struct Splay
{
	struct node
	{
		int key;
		node *p, *s[2];
		int size, num;
		node()
		{
			p = s[0] = s[1] = nullptr;
			size = num = 1;
			key = 0;
		}
		node(int x)
			:key(x)
		{
			p = s[0] = s[1] = nullptr;
			size = num = 1;
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
		void update()
		{
			size = num + (s[0] ? s[0]->size : 0) + (s[1] ? s[1]->size : 0);
		}
	};
	node *root;
	Splay() { root = nullptr; }
	void rot(node *n)
	{
		node *g = n->p->p;
		n->getlr() ? n->link(0, n->p->link(1, n->s[0])) : n->link(1, n->p->link(0, n->s[1]));
		n->p->update();
		if (g) g->link(g->s[1] == n->p, n);
		else { n->p = nullptr; root = n; }
	}
	void splay(node *n, node *tar)
	{
		while (n->p != tar && n->p->p != tar)
			n->getlr() == n->p->getlr() ? (rot(n->p), rot(n)) : (rot(n), rot(n));
		if (n->p != tar) rot(n);
		n->update();
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
		if (find(x)) { root->num += 1; root->update(); return; }
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
	node* findKth(int k)
	{
		if (root->size < k) return nullptr;
		node* cur = root;
		while (!(((cur->s[0] ? cur->s[0]->size : 0) < k) && ((cur->s[0] ? cur->s[0]->size : 0) + cur->num >= k)))
			if (!cur->s[0])
			{
				k -= cur->num;
				cur = cur->s[1];
			}
			else
			{
				if (cur->s[0]->size >= k) cur = cur->s[0];
				else
				{
					k = k - cur->s[0]->size - cur->num;
					cur = cur->s[1];
				}
			}
		if (cur) splay(cur, nullptr);
		return cur;
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
		if (!low) { root->s[0] = nullptr; root->update(); return; }
		if (!upp) { splay(low, nullptr); root->s[1] = nullptr; root->update(); return; }
		splay(low, upp);
		low->s[1] = nullptr;
		low->update();
		upp->update();
	}
	void delone(int x)
	{
		node* d = find(x);
		if (!d) return;
		if (d->num > 1)
		{
			d->num -= 1;
			d->update();
		}
		else del(x, x);
	}
};

int main()
{
	cin.sync_with_stdio(0); cin.tie(0);
	Splay tr;
	int n;
	cin >> n;
	char order[30];
	int a, b;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < 30; i++) order[i] = '\0';
		cin >> order;
		if (strlen(order) == 6 && order[0] == 'i') //insert
		{
			cin >> a;
			tr.insert(a);
		}
		if (strlen(order) == 6 && order[0] == 'd') //delete
		{
			cin >> a;
			tr.delone(a);
		}
		if (strlen(order) == 16) //delete_less_than
		{
			cin >> a;
			tr.del(INT32_MIN, a - 1);
		}
		if (strlen(order) == 19) //delete_greater_than
		{
			cin >> a;
			tr.del(a + 1, INT32_MAX);
		}
		if (strlen(order) == 15) //delete_interval
		{
			cin >> a >> b;
			if (a + 1 <= b - 1)
				tr.del(a + 1, b - 1);
		}
		if (strlen(order) == 4) //find
		{
			cin >> a;
			Splay::node *f = tr.find(a);
			if (f) printf("Y\n");
			else printf("N\n");
		}
		if (strlen(order) == 8) //find_ith
		{
			cin >> a;
			Splay::node *f = tr.findKth(a);
			if (!f) printf("N\n");
			else printf("%d\n", f->key);
		}
	}
	return 0;
}
