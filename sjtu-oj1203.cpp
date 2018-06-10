#include <iostream>
#include <string>

using namespace std;

template<class T>
class List
{
private:
	class node
	{
	public:
		T val;
		node *next;
		node() :val(0), next(NULL) {}
		node(T v) :val(v), next(NULL) {}
	};
	node *head;
	node *tail;
public:
	List()
	{
		head = new node();
		tail = head;
	}
	void Add(T newval)
	{
		tail->next = new node(newval);
		tail = tail->next;
	}
	List<T> operator+(const List<T> &rhs) const
	{
		List<T> res;
		node *cur = head->next;
		while (cur)
		{
			res.Add(cur->val);
			cur = cur->next;
		}
		cur = rhs.head->next;
		while (cur)
		{
			res.Add(cur->val);
			cur = cur->next;
		}
		return res;
	}
	void Print()
	{
		node *cur = head->next;
		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main()
{
	string t;
	cin >> t;
	int l1, l2;
	cin >> l1 >> l2;
	if (t == "int")
	{
		List<int> list1;
		List<int> list2;
		int num;
		for (int i = 0; i < l1; i++)
		{
			cin >> num;
			list1.Add(num);
		}
		for (int i = 0; i < l2; i++)
		{
			cin >> num;
			list2.Add(num);
		}
		(list1 + list2).Print();
	}
	if (t == "char")
	{
		List<char> list1;
		List<char> list2;
		char num;
		for (int i = 0; i < l1; i++)
		{
			cin >> num;
			while (num == ' ') cin >> num;
			list1.Add(num);
		}
		for (int i = 0; i < l2; i++)
		{
			cin >> num;
			while (num == ' ') cin >> num;
			list2.Add(num);
		}
		(list1 + list2).Print();
	}
	if (t == "double")
	{
		List<double> list1;
		List<double> list2;
		double num;
		for (int i = 0; i < l1; i++)
		{
			cin >> num;
			list1.Add(num);
		}
		for (int i = 0; i < l2; i++)
		{
			cin >> num;
			list2.Add(num);
		}
		(list1 + list2).Print();
	}
	return 0;
}