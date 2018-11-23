#include <iostream>

using namespace std;

class node {
public:
	int val;
	node* nxt;
	node* pre;
	node()
		:val(0), nxt(nullptr), pre(nullptr) {}
	node(int v)
		:val(v), nxt(nullptr), pre(nullptr) {}
};

class linklist {
public:
	node* head;
	node* cur;
	int size;
	linklist(int n) {
		size = n;
		head = new node(1);
		cur = head;
		for (int i = 2; i <= n; i++) {
			cur->nxt = new node(i);
			cur->nxt->pre = cur;
			cur = cur->nxt;
		}
		cur = head;
		return;
	}
	void delM(int m, bool pr) {
		m = m % size;
		size -= 1;
		for (int i = 0; i < m; i++) {
			if (cur->nxt) cur = cur->nxt;
			else cur = head;
		}
		if (pr) {
			cout << cur->val << endl;
			return;
		}
		if (cur->pre == nullptr) {
			head = cur->nxt;
			cur = cur->nxt;
			head->pre = nullptr;
		}
		else {
			node* PRE = cur->pre;
			node* NXT = cur->nxt;
			PRE->nxt = NXT;
			if (NXT) {
				NXT->pre = PRE;
				cur = cur->nxt;
			}
			else cur = head;
		}
		return;
	}
};

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	linklist* l = new linklist(N);
	for (int i = 0; i < K - 1; i++) l->delM(M - 1, false);
	l->delM(M - 1, true);
	return 0;
}