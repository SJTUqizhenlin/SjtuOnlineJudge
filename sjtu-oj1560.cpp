#include <stdio.h>
#include <vector>
using namespace std;

struct node {
	int val; node *l, *r, *p;
	node(int vval) :val(vval), l(nullptr), r(nullptr), p(nullptr) {}
};

node *root = nullptr;
char pathstr[100005];
int pathlen = 0;

void insertTr(int x) {
	if (!root) {
		root = new node(x);
		return;
	}
	if (root->val == x) return;
	node *cur = root;
	while (true) {
		if (x < cur->val) {
			if (cur->l && cur->l->val != x) cur = cur->l;
			else {
				if (cur->l == nullptr) {
					cur->l = new node(x);
					cur->l->p = cur;
				}
				else break;
			}
		}
		else {
			if (cur->r && cur->r->val != x) cur = cur->r;
			else {
				if (cur->r == nullptr) {
					cur->r = new node(x);
					cur->r->p = cur;
				}
				else break;
			}
		}
	}
	return;
}

node* findTr(int x) {
	if (!root) return nullptr;
	pathstr[0] = '*'; pathlen = 0;
	if (root->val == x) return root;
	node *cur = root;
	while (true) {
		if (x < cur->val) {
			if (cur->l == nullptr) break;
			else {
				pathstr[++pathlen] = 'l';
				if (cur->l->val == x) return (cur->l);
				else cur = cur->l;
			}
		}
		else {
			if (cur->r == nullptr) break;
			else {
				pathstr[++pathlen] = 'r';
				if (cur->r->val == x) return (cur->r);
				else cur = cur->r;
			}
		}
	}
	return nullptr;
}

void eraseTr(int x) {
	node *q = findTr(x);
	if (q == nullptr) return;
	if (q->l == nullptr && q->r == nullptr) {
		if (q == root) root = nullptr;
		else {
			if (q == q->p->l) q->p->l = nullptr;
			else q->p->r = nullptr;
		}
		return;
	}
	if (q->r == nullptr) {
		if (q == root) {
			root = q->l; 
			root->p = nullptr;
		}
		else {
			if (q == q->p->l) q->p->l = q->l;
			else q->p->r = q->l;
			q->l->p = q->p;
		} return;
	}
	node *del = q->r;
	while (del->l) del = del->l;
	q->val = del->val;
	if (del == del->p->l) del->p->l = del->r;
	else del->p->r = del->r;
	if (del->r) del->r->p = del->p;
	return;
}

int main() {
	int Q; scanf("%d", &Q);
	char op; int num;
	while (Q--) {
		scanf("%c", &op);
		while (!(op == '+' || op == '-' || op == '*'))
			scanf("%c", &op);
		scanf("%d", &num);
		if (op == '+') insertTr(num);
		if (op == '-') eraseTr(num);
		if (op == '*') {
			node *f = findTr(num);
			if (!f) printf("Nothing.\n");
			else {
				for (int i = 0; i <= pathlen; i++)
					printf("%c", pathstr[i]);
				printf("\n");
			}
		}
	}
	return 0;
}