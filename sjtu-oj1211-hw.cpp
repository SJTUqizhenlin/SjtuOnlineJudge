#include <iostream>
#include <string.h>

using namespace std;

int N;

class node {
public:
	int val;
	node* lson;
	node* rson;
	node* par;
	node() :val(0), lson(nullptr), rson(nullptr), par(nullptr) {}
	node(int v) :val(v), lson(nullptr), rson(nullptr), par(nullptr) {}
};

node* tree;

bool check(node* n, int id) {
	if (id > N) return false;
	bool res = true;
	if (n->lson) res = res && check(n->lson, id * 2);
	if (n->rson) res = res && check(n->rson, id * 2 + 1);
	return res;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	tree = new node[N + 1];
	int l, r;
	for (int i = 1; i <= N; i++) {
		cin >> l >> r;
		tree[i].val = i;
		if (l) {
			tree[i].lson = &(tree[l]);
			tree[l].par = &(tree[i]);
		}
		if (r) {
			tree[i].rson = &(tree[r]);
			tree[r].par = &(tree[i]);
		}
	}
	int root_id = 1;
	while (tree[root_id].par)
		root_id = tree[root_id].par->val;
	bool res = check(&(tree[root_id]), 1);
	cout << (res ? "Y" : "N") << endl;
	return 0;
}