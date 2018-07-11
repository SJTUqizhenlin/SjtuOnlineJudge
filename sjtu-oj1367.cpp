#include <stdio.h>

using namespace std;

const int MAXbit = 31;
int bitarr[MAXbit];

struct trnode
{
	int size;
	trnode* chd[2];
	trnode() :size(1)
	{
		chd[0] = chd[1] = nullptr;
	}
};

void in_bitarr()
{
	int x = 1;
	for (int i = 0; i < MAXbit; i++)
	{
		bitarr[i] = x;
		x <<= 1;
	}
	return;
}

void tr_add(trnode* root, int x, int i)
{
	if (i == 0) return;
	int onebit = x & bitarr[i - 1];
	if (onebit)
	{
		if (root->chd[1]) { root->chd[1]->size++; tr_add(root->chd[1], x, i - 1); }
		else { root->chd[1] = new trnode(); tr_add(root->chd[1], x, i - 1); }
	}
	else
	{
		if (root->chd[0]) { root->chd[0]->size++; tr_add(root->chd[0], x, i - 1); }
		else { root->chd[0] = new trnode(); tr_add(root->chd[0], x, i - 1); }
	}
	return;
}

void maxXor(int x, trnode* root, int &ares, int i)
{
	if (i == 0) return;
	int abit = x & bitarr[i - 1];
	if (abit)
	{
		if (root->chd[0]) { ares += bitarr[i - 1]; maxXor(x, root->chd[0], ares, i - 1); }
		else if (root->chd[1]) { maxXor(x, root->chd[1], ares, i - 1); }
	}
	else
	{
		if (root->chd[1]) { ares += bitarr[i - 1]; maxXor(x, root->chd[1], ares, i - 1); }
		else if (root->chd[0]) { maxXor(x, root->chd[0], ares, i - 1); }
	}
	return;
}

int main()
{
	in_bitarr();
	int n, m;
	scanf("%d%d", &n, &m);
	int *arr = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int tmp;
	trnode *tr = new trnode();
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &tmp);
		tr_add(tr, tmp, MAXbit);
	}
	//printf("%d\n", tr->chd[0]->chd[1]->chd[0]->size);
	int ares, res = 0;
	for (int i = 0; i < n; i++)
	{
		ares = 0;
		maxXor(arr[i], tr, ares, MAXbit);
		if (ares > res) res = ares;
	}
	printf("%d\n", res);
	return 0;
}