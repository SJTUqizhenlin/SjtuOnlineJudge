#include <cstdio>

int ans;

struct Splay
{
	struct node
	{
		node *p, *s[2];
		int key, size, num;
		node() { p = s[0] = s[1] = 0; size = num = 1; key = 0; }
		node(int key) :key(key) { p = s[0] = s[1] = 0; size = num = 1; }
		bool getlr() { return p->s[1] == this; }
		node *link(int w, node *p) { s[w] = p; if (p)p->p = this; return this; }
		void update() { size = num + (s[0] ? s[0]->size : 0) + (s[1] ? s[1]->size : 0); }
	} *root;
	void rot(node *p)
	{
		node *q = p->p->p;
		p->getlr() ? p->link(0, p->p->link(1, p->s[0])) : p->link(1, p->p->link(0, p->s[1]));
		p->p->update();
		if (q)q->link(q->s[1] == p->p, p); else { p->p = 0; root = p; }
	}
	void splay(node *p, node *tar)
	{
		while (p->p != tar && p->p->p != tar)
			p->getlr() == p->p->getlr() ? (rot(p->p), rot(p)) : (rot(p), rot(p));
		if (p->p != tar)rot(p);
		p->update();
	}
	void preset() { root = 0; }
	node *find(int x)
	{
		node *p = root;
		while (p && p->key != x)p = p->s[p->key < x];
		if (p)splay(p, 0);
		return p;
	}
	void insert(int x)
	{
		if (!root) { root = new node(x); return; }
		if (find(x)) { ++root->num; root->update(); return; }
		node *p = root, *p1;
		while (p) { p1 = p; p = p->s[p->key < x]; }
		p = new node(x);
		p1->link(p1->key < x, p);
		splay(p, 0);
	}
	node *findKth(int k)
	{
		if (root->size < k)return 0;
		node *p = root;
		while (!(((p->s[0] ? p->s[0]->size : 0) < k) && ((p->s[0] ? p->s[0]->size : 0) + p->num >= k)))
			if (!p->s[0]) { k -= p->num; p = p->s[1]; }
			else { if (p->s[0]->size >= k)p = p->s[0]; else { k = k - p->s[0]->size - p->num; p = p->s[1]; } }
			if (p)splay(p, 0);
			return p;
	}
	node *prev()
	{
		node *p = root->s[0];
		if (!p)return 0;
		while (p->s[1])p = p->s[1];
		splay(p, 0);
		return p;
	}
	node *succ()
	{
		node *p = root->s[1];
		if (!p)return 0;
		while (p->s[0])p = p->s[0];
		splay(p, 0);
		return p;
	}
	void del(int l, int r)
	{
		if (!find(l)) { insert(l); --ans; }
		node *p = prev();
		if (!find(r)) { insert(r); --ans; }
		node *q = succ();
		if (!p && !q) { ans += root->size; preset(); return; }
		if (!p) { ans += root->s[0] ? root->s[0]->size : 0; root->s[0] = 0; root->update(); return; }
		if (!q) { splay(p, 0); ans += root->s[1] ? root->s[1]->size : 0; root->s[1] = 0; root->update(); return; }
		splay(p, q);
		if (p->s[1])ans += p->s[1]->size;
		p->s[1] = 0;
		p->update();
		q->update();
	}
}S;

int n, m;
char sign; int x;

int main()
{
	scanf("%d%d", &n, &m);
	int delta = 0;
	S.preset();
	ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("\n%c %d", &sign, &x);
		switch (sign)
		{
		case 'I': if (x >= m)S.insert(x - delta); break;
		case 'A': delta += x; break;
		case 'S': delta -= x; S.del(-100000, m - delta - 1); break;
		case 'F': if (!S.root || x > S.root->size)printf("-1\n"); else { S.findKth(S.root->size + 1 - x); printf("%d\n", S.root->key + delta); }
		}
	}
	printf("%d\n", ans);
	return 0;
}