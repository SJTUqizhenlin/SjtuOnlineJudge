#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
	int val;
	node *next;
	node() :val(0), next(NULL) {}
	node(int v) :val(v), next(NULL) {}
};

struct HPint
{
	node *head;
	node *tail;
	HPint()
	{
		head = new node();
		head->next = new node();
		tail = head->next;
	}
	HPint(const HPint &rhs)
	{
		head = new node();
		head->next = new node();
		tail = head->next;
		node *cur = rhs.head->next;
		while (cur != rhs.tail)
		{
			tail->val = cur->val;
			tail->next = new node();
			tail = tail->next;
			cur = cur->next;
		}
	}
	HPint operator=(const HPint &rhs)
	{
		node *cur = rhs.head->next;
		while (cur != rhs.tail)
		{
			tail->val = cur->val;
			tail->next = new node();
			tail = tail->next;
			cur = cur->next;
		}
		return *this;
	}
	HPint(string s)
	{
		head = new node();
		head->next = new node();
		tail = head->next;
		int i = s.length() - 1;
		for (; i >= 0; i--)
		{
			tail->val = s[i] - '0';
			tail->next = new node();
			tail = tail->next;
		}
	}
	HPint operator+(const HPint &rhs) const
	{
		HPint res;
		node *n1 = this->head->next;
		node *n2 = rhs.head->next;
		while (n1 != this->tail && n2 != rhs.tail)
		{
			res.tail->val += (n1->val + n2->val);
			res.tail->next = new node(res.tail->val / 10);
			res.tail->val %= 10;
			res.tail = res.tail->next;
			n1 = n1->next;
			n2 = n2->next;
		}
		if (n1 != this->tail)
		{
			while (n1 != this->tail)
			{
				res.tail->val += n1->val;
				res.tail->next = new node(res.tail->val / 10);
				res.tail->val %= 10;
				res.tail = res.tail->next;
				n1 = n1->next;
			}
		}
		if (n2 != rhs.tail)
		{
			while (n2 != rhs.tail)
			{
				res.tail->val += n2->val;
				res.tail->next = new node(res.tail->val / 10);
				res.tail->val %= 10;
				res.tail = res.tail->next;
				n2 = n2->next;
			}
		}
		if (res.tail->val)
		{
			res.tail->next = new node();
			res.tail = res.tail->next;
		}
		return res;
	}
	string Show()
	{
		string res = "";
		node *cur = head->next;
		while (cur != tail)
		{
			res.append(1, '0' + cur->val);
			cur = cur->next;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	string i1;
	string i2;
	cin >> i1 >> i2;
	HPint h1(i1);
	HPint h2(i2);
	HPint h3 = h1 + h2;
	cout << h3.Show() << endl;
	return 0;
}