#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class BnHeap {
public:
	class Node {
	public:
		int val;
		Node* lson; Node* rsib;
		Node() :val(0), lson(nullptr), rsib(nullptr){}
		Node(int v) :val(v), lson(nullptr), rsib(nullptr){}
	};
	static const int MR = 17;
	Node* Roots[MR];
	BnHeap() {
		for (int i = 0; i < MR; i++)
			Roots[i] = nullptr;
	}
	void init(int v) {
		Roots[0] = new Node(v);
		return;
	}
	Node* unite_root(Node* r1, Node* r2) {
		if (!(r1->lson)) {
			r1->lson = r2;
		}
		else {
			Node* cur = r1->lson;
			while (cur->rsib) cur = cur->rsib;
			cur->rsib = r2;
		}
		return r1;
	}
	void Unite_Heap(BnHeap* b) {
		Node* c = nullptr;
		for (int i = 0; i < MR; i++) {
			int tmp = (Roots[i] ? 1 : 0) + (b->Roots[i] ? 1 : 0) + (c ? 1 : 0);
			if (tmp == 0) continue;
			if (tmp == 1) {
				if (b->Roots[i]) Roots[i] = b->Roots[i];
				if (c) Roots[i] = c;
				c = nullptr;
				continue;
			}
			if (tmp == 2) {
				if (!Roots[i]) {
					if (b->Roots[i]->val < c->val)
						c = unite_root(b->Roots[i], c);
					else
						c = unite_root(c, b->Roots[i]);
				}
				if (!(b->Roots[i])) {
					if (Roots[i]->val < c->val)
						c = unite_root(Roots[i], c);
					else
						c = unite_root(c, Roots[i]);
				}
				if (!c) {
					if (Roots[i]->val < b->Roots[i]->val)
						c = unite_root(Roots[i], b->Roots[i]);
					else
						c = unite_root(b->Roots[i], Roots[i]);
				}
				Roots[i] = nullptr;
			}
			if (tmp == 3) {
				if (b->Roots[i]->val < c->val)
					c = unite_root(b->Roots[i], c);
				else
					c = unite_root(c, b->Roots[i]);
			}
		}
		return;
	}
	int Get_Min() {
		int ret = INT32_MAX;
		for (int i = 0; i < MR; i++) {
			if (Roots[i])
				if (ret > Roots[i]->val)
					ret = Roots[i]->val;
		}
		return ret;
	}
	void Del_Min() {
		int ret = INT32_MAX;
		int minid = -1;
		for (int i = 0; i < MR; i++) {
			if (Roots[i])
				if (ret > Roots[i]->val) {
					ret = Roots[i]->val;
					minid = i;
				}
		}
		BnHeap* b = new BnHeap();
		Node* cur = Roots[minid]->lson;
		int id = 0;
		while (cur) {
			b->Roots[id] = cur;
			cur = cur->rsib;
			id += 1;
		}
		Roots[minid] = nullptr;
		for (int i = 0; i < MR; i++) {
			if (b->Roots[i])
				b->Roots[i]->rsib = nullptr;
		}
		this->Unite_Heap(b);
		return;
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int M; cin >> M;
	string cmmd; int tmp;
	BnHeap* h = new BnHeap();
	for (int i = 0; i < M; i++) {
		cin >> cmmd;
		if (cmmd[0] == 'i') {
			cin >> tmp;
			BnHeap* b = new BnHeap();
			b->init(tmp);
			h->Unite_Heap(b);
		}
		if (cmmd[0] == 'd') {
			h->Del_Min();
		}
		if (cmmd[0] == 'm') {
			cout << h->Get_Min() << endl;
		}
	}
	return 0;
}