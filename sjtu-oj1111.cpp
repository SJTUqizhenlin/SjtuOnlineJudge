#include <iostream>
#include <string>

using namespace std;

struct node
{
	char val;
	node *left;
	node* right;
	node() :val(0), left(nullptr), right(nullptr) {}
	node(char v)
		:val(v), left(nullptr), right(nullptr) {}
};

node* Setup(string s1, string s2)
{
	node *cur_root = new node(s1[0]);
	int ind = 0;
	for (; ind < s2.length(); ind++)
		if (s1[0] == s2[ind]) break;
	if (ind > 0)
		cur_root->left = Setup(s1.substr(1, ind), s2.substr(0, ind));
	if (ind < s2.length() - 1)
		cur_root->right = Setup(s1.substr(ind + 1, s1.length() - ind - 1), s2.substr(ind + 1, s2.length() - ind - 1));
	return cur_root;
}

void Fillin(node *root, int *arr, int pos)
{
	arr[pos] = root->val - 'A' + 1;
	if (root->left != nullptr)
		Fillin(root->left, arr, pos * 2);
	if (root->right != nullptr)
		Fillin(root->right, arr, pos * 2 + 1);
	return;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	node *root = Setup(s1, s2);
	int arr[1005];
	for (int i = 0; i < 1005; i++) arr[i] = 0;
	Fillin(root, arr, 1);
	int tail = 1004;
	for (; tail >= 0; tail--)
		if (arr[tail]) break;
	for (int i = 1; i <= tail; i++)
	{
		if (arr[i])
			cout << char(arr[i] - 1 + 'A') << " ";
		else
			cout << "NULL ";
	}
	cout << endl;
	return 0;
}