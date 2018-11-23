#include <iostream>
using namespace std;

class binTree {
public:
	class Node {
	public:
		int val;
		Node* lson; Node* rson; Node* par;
		Node() :val(0), lson(nullptr), rson(nullptr), par(nullptr) {}
		Node(int v) :val(v),lson(nullptr),rson(nullptr), par(nullptr) {}
	};
	Node *Root;
	binTree() {
		Root = nullptr;
	}
	Node* Find(int x) {
		Node* pre = nullptr; Node* cur = Root;
		while (cur) {
			if (cur->val == x) return cur;
			if (x < cur->val) {
				pre = cur;
				cur = cur->lson;
			}
			else {
				pre = cur;
				cur = cur->rson;
			}
		}
		return cur;
	}
	void Insert(int x) {
		if (Find(x)) return;
		if (!Root) { Root = new Node(x); return; }
		Node* cur = Root; Node* pre = nullptr;
		while (cur) {
			pre = cur;
			if (cur->val > x) cur = cur->lson;
			else cur = cur->rson;
		}
		if (pre->val > x) {
			pre->lson = new Node(x);
			pre->lson->par = pre;
		}
		else {
			pre->rson = new Node(x);
			pre->rson->par = pre;
		}
		return;
	}
	void Delete(int x) {
		Node* tar = Find(x);
		if (!tar) return;
		Node* tarp = tar->par;
		if (!(tar->lson) && !(tar->rson)) {
			if (!tarp) {
				Root = nullptr;
				return;
			}
			else {
				if (tar == tarp->lson) tarp->lson = nullptr;
				else tarp->rson = nullptr;
				return;
			}
		}
		else {
			if (!(tar->rson)) {
				if (tar == Root) {
					Root = tar->lson;
					Root->par = nullptr;
					return;
				}
				else {
					if (tar == tarp->lson) {
						tarp->lson = tar->lson;
						tarp->lson->par = tarp;
					}
					else {
						tarp->rson = tar->lson;
						tarp->rson->par = tarp;
					}
				}
			}
			else {
				Node* succ = tar->rson;
				while (succ->lson) succ = succ->lson;
				tar->val = succ->val;
				Node* succp = succ->par;
				Node* succs = succ->rson;
				if (succ == succp->lson) {
					succp->lson = succs;
					if (succs) succs->par = succp;
				}
				else {
					succp->rson = succs;
					if (succs) succs->par = succp;
				}
			}
		}
		return;
	}
	void List(Node* root) {
		if (!root) return;
		List(root->lson);
		cout << root->val << " ";
		List(root->rson);
		return;
	}
};

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	char o; int M;
	binTree* tr = new binTree();
	for (int i = 0; i < N; ++i) {
		cin >> o;
		cin >> M;
		int tmp;
		switch (o) {
		case '+':
			for (int j = 0; j < M; ++j) {
				cin >> tmp;
				tr->Insert(tmp);
			}
			tr->List(tr->Root); cout << "\n";
			break;
		case '-':
			for (int j = 0; j < M; ++j) {
				cin >> tmp;
				tr->Delete(tmp);
			}
			tr->List(tr->Root); cout << "\n";
			break;
		case '*':
			binTree* newtr = new binTree();
			for (int j = 0; j < M; ++j) {
				cin >> tmp;
				binTree::Node* f = tr->Find(tmp);
				if (f == nullptr) continue;
				if (f->val != tmp) continue;
				if (f->val == tmp) newtr->Insert(tmp);
			}
			tr = newtr;
			tr->List(tr->Root); cout << "\n";
			break;
		}
	}
	return 0;
}
