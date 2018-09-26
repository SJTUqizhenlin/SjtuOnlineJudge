#include <iostream>

using namespace std;

template <class T>
class linkedList {
private:
	class listNode {
	public:
		T value;
		listNode *next;
		listNode() :value(0), next(nullptr) {}
		listNode(T v) :value(v), next(nullptr) {}
	};
public:
	listNode *headNode;
	listNode *tailNode;
	linkedList() {
		headNode = new listNode();
		tailNode = headNode;
	}
	void appendVal(T val) {
		tailNode->next = new listNode(val);
		tailNode = tailNode->next;
	}
	void printSelf() {
		listNode *cur = headNode->next;
		while (cur) {
			cout << cur->value << " ";
			cur = cur->next;
		}
		return;
	}
	void appendList(linkedList<T> *L) {
		this->tailNode->next = L->headNode->next;
		return;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	char *type_name = new char[20];
	cin >> type_name;
	int a, b;
	cin >> a >> b;
	switch (*type_name) {
	case 'i': {
		linkedList<int> *l1 = new linkedList<int>();
		linkedList<int> *l2 = new linkedList<int>();
		int tmp;
		for (int i = 0; i < a; i++) {
			cin >> tmp;
			l1->appendVal(tmp);
		}
		for (int i = 0; i < b; i++) {
			cin >> tmp;
			l2->appendVal(tmp);
		}
		l1->appendList(l2);
		l1->printSelf();
		break;
	}
	case 'c': {
		linkedList<char> *l1 = new linkedList<char>();
		linkedList<char> *l2 = new linkedList<char>();
		char tmp;
		for (int i = 0; i < a; i++) {
			cin >> tmp;
			while (tmp == ' ') cin >> tmp;
			l1->appendVal(tmp);
		}
		for (int i = 0; i < b; i++) {
			cin >> tmp;
			while (tmp == ' ') cin >> tmp;
			l2->appendVal(tmp);
		}
		l1->appendList(l2);
		l1->printSelf();
		break;
	}
	case 'd': {
		linkedList<double> *l1 = new linkedList<double>();
		linkedList<double> *l2 = new linkedList<double>();
		double tmp;
		for (int i = 0; i < a; i++) {
			cin >> tmp;
			l1->appendVal(tmp);
		}
		for (int i = 0; i < b; i++) {
			cin >> tmp;
			l2->appendVal(tmp);
		}
		l1->appendList(l2);
		l1->printSelf();
		break;
	}
	}
	return 0;
}