#include <stdio.h>

using namespace std;

struct LinkList
{
	struct node
	{
		int val; 
		node* next;
		node() :val(0), next(nullptr) {}
		node(int x) :val(x), next(nullptr) {}
	};
	node *head, *tail;
	LinkList()
	{
		head = new node();
		tail = head;
	}
	void Add(int x)
	{
		tail->next = new node(x);
		tail = tail->next;
	}
	void Print()
	{
		node *cur = head;
		while (cur->next) { printf("%d ", cur->next->val); cur = cur->next; }
		return;
	}
};

void Merges(LinkList &a, LinkList &b)
{
	LinkList::node *newcur = a.head;
	LinkList::node *tmpa = new LinkList::node();
	tmpa->next = a.head->next;
	LinkList::node *tmpb = new LinkList::node();
	tmpb->next = b.head->next;
	while (tmpa->next && tmpb->next)
	{
		if (tmpa->next->val < tmpb->next->val)
		{
			newcur->next = tmpa->next;
			newcur = newcur->next;
			tmpa->next = tmpa->next->next;
		}
		else
		{
			newcur->next = tmpb->next;
			newcur = newcur->next;
			tmpb->next = tmpb->next->next;
		}
	}
	if (tmpa->next) newcur->next = tmpa->next;
	if (tmpb->next) newcur->next = tmpb->next;
	return;
}

int main()
{
	int m, n, val;
	scanf("%d%d", &m, &n);
	LinkList a, b;
	for (int i = 0; i < m; i++) { scanf("%d", &val); a.Add(val); }
	for (int i = 0; i < n; i++) { scanf("%d", &val); b.Add(val); }
	Merges(a, b);
	a.Print();
	printf("\n");
	return 0;
}
