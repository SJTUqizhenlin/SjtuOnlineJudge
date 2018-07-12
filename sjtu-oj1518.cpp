#include <stdio.h>
using namespace std;

struct node {
	int val;
	node *l, *r;
	node() :val(0), l(nullptr), r(nullptr) {}
	node(int vval):val(vval), l(nullptr), r(nullptr) {}
};

node *Root;
int pre_arr[100005];
int in_arr[100005];
int N;

void init_arr() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &(pre_arr[i]));
	for (int i = 1; i <= N; i++) scanf("%d", &(in_arr[i]));
	return;
}

node* set_up(int p1, int p2, int i1, int i2) {
	node *root = new node(pre_arr[p1]);
	int mid = i1;
	while (in_arr[mid] != pre_arr[p1]) mid++;
	if (mid > i1) root->l = set_up(p1 + 1, p1 + mid - i1, i1, mid - 1);
	if (i2 > mid) root->r = set_up(p1 + mid - i1 + 1, p2, mid + 1, i2);
	return root;
}

void post_trav(node *root) {
	if (root->l) post_trav(root->l);
	if (root->r) post_trav(root->r);
	printf("%d ", root->val);
	return;
}

int main() {
	init_arr();
	Root = set_up(1, N, 1, N);
	post_trav(Root);
	return 0;
}