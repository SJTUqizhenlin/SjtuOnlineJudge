//#include <iostream>
//#include <string.h>
//
//using namespace std;
//
//char s_pre[50];
//char s_mid[50];
//char res[2010];
//int maxN = 0;
//
//class node {
//public:
//	char val;
//	node* lson;
//	node* rson;
//	node* par;
//	node() :val(0), lson(nullptr), rson(nullptr), par(nullptr) {}
//	node(char v) :val(v), lson(nullptr), rson(nullptr), par(nullptr) {}
//};
//
//node* build_tree(int pre_beg, int pre_end, int mid_beg, int mid_end) {
//	node* root = new node(s_pre[pre_beg]);
//	if (pre_beg == pre_end) return root;
//	int id = mid_beg;
//	while (s_mid[id] != s_pre[pre_beg]) ++id;
//	if (id > mid_beg) {
//		root->lson = build_tree(pre_beg + 1, pre_beg + id - mid_beg, mid_beg, id - 1);
//		root->lson->par = root;
//	}
//	if (id < mid_end) {
//		root->rson = build_tree(pre_beg + id - mid_beg + 1, pre_end, id + 1, mid_end);
//		root->rson->par = root;
//	}
//	return root;
//}
//void to_arr(node* root, int id) {
//	res[id] = root->val;
//	if (id >= maxN) maxN = id;
//	if (root->lson) to_arr(root->lson, id * 2);
//	if (root->rson) to_arr(root->rson, id * 2 + 1);
//	return;
//}
//
//int main() {
//	cin.get(s_pre, 40);
//	cin.get();
//	cin.get(s_mid, 40);
//	int Len = strlen(s_pre);
//	node* Root = build_tree(0, Len - 1, 0, Len - 1);
//	for (int i = 0; i < 2010; i++) res[i] = '\0';
//	to_arr(Root, 1);
//	for (int i = 1; i <= maxN; i++)
//		if (res[i] == '\0') cout << "NULL ";
//		else cout << res[i] << " ";
//	cout << endl;
//	return 0;
//}
