#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_IND = (1 << 19) - 1;
const int max_n = 1 << 18;
int bin_t[MAX_IND];

void add_in_0(int x, int lbound, int ubound, int node)
{
	if (node >= MAX_IND) return;
	bin_t[node]++;
	if (ubound > lbound)
	{
		int mid = (lbound + ubound) / 2;
		bin_t[node * 2 + 1] = 0;
		bin_t[node * 2 + 2] = 0;
		if (x <= mid) add_in_0(x, lbound, mid, node * 2 + 1);
		else add_in_0(x, mid + 1, ubound, node * 2 + 2);
	}
}

void add_in(int x, int lbound, int ubound, int node)
{
	if (node >= MAX_IND) return;
	if (bin_t[node] == 0)
	{
		add_in_0(x, lbound, ubound, node);
		return;
	}
	bin_t[node]++;
	if (ubound > lbound)
	{
		int mid = (lbound + ubound) / 2;
		if (x <= mid) add_in(x, lbound, mid, node * 2 + 1);
		else add_in(x, mid + 1, ubound, node * 2 + 2);
	}
	return;
}

void delete_in(int p, int q, int &sum, int lbound, int ubound, int node)
{
	if (node >= MAX_IND) return;
	if (bin_t[node] == 0) return;
	if (lbound > q || ubound < p) return;
	if (lbound >= p && ubound <= q)
	{
		sum += bin_t[node];
		int minu = bin_t[node];
		while (node > 0)
		{
			bin_t[node] -= minu;
			node = (node - 1) / 2;
		}
		bin_t[0] -= minu;
		return;
	}
	int mid = (lbound + ubound) / 2;
	delete_in(p, q, sum, lbound, mid, node * 2 + 1);
	delete_in(p, q, sum, mid + 1, ubound, node * 2 + 2);
	return;
}

int find_maxk(int k, int lbound, int ubound, int node)
{
	if (node >= MAX_IND) return 0;
	if (k > bin_t[node]) return 0;
	if (lbound == ubound) return lbound;
	int mid = (lbound + ubound) / 2;
	if (k <= bin_t[node * 2 + 2]) return find_maxk(k, mid + 1, ubound, node * 2 + 2);
	else return find_maxk(k - bin_t[node * 2 + 2], lbound, mid, node * 2 + 1);
}

int main()
{
	int M, x, y;
	scanf("%d", &M);
	char op;
	int sum, maxk;
	for (int i = 0; i < M; i++)
	{
		scanf("\n%c", &op);
		if (op == 'Z')
		{
			scanf("%d", &x);
			add_in(x, 1, max_n, 0);
		}
		if (op == 'S')
		{
			scanf("%d%d", &x, &y);
			sum = 0;
			delete_in(x, y, sum, 1, max_n, 0);
			printf("%d\n", sum);
		}
		if (op == 'L')
		{
			scanf("%d", &x);
			maxk = find_maxk(x, 1, max_n, 0);
			printf("%d\n", maxk);
		}
	}
	return 0;
}